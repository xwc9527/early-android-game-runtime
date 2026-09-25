import unittest

from parse_trace_log import parse_lines


class TraceLogTest(unittest.TestCase):
    def test_declared_and_resolved_target_stay_distinct(self):
        line = ("09-25 12:34:56.789  123  124 I dalvikvm: AGRTRACE|v1|1|"
                "Lgame/Main;->start()V|7|110|12|"
                "Landroid/app/Activity;->setContentView(I)V|"
                "Landroid/app/Activity;->setContentView(I)V")
        event = parse_lines([line])[0]
        self.assertEqual(event["method_idx"], 12)
        self.assertEqual(event["dex_pc"], 7)
        self.assertEqual(event["caller"], "Lgame/Main;->start()V")

    def test_missing_record_fails_closed(self):
        lines = [
            "09-25 12:34:56.789  123  124 I dalvikvm: AGRTRACE|v1|1|Lgame/A;->x()V|0|110|1|Ljava/lang/Object;->wait()V|Ljava/lang/Object;->wait()V",
            "09-25 12:34:56.790  123  124 I dalvikvm: AGRTRACE|v1|3|Lgame/A;->x()V|3|110|1|Ljava/lang/Object;->wait()V|Ljava/lang/Object;->wait()V",
        ]
        with self.assertRaisesRegex(ValueError, "sequence gap"):
            parse_lines(lines)

    def test_concurrent_threads_can_arrive_out_of_sequence(self):
        template = ("09-25 12:34:56.789  123  124 I dalvikvm: AGRTRACE|v1|{}|"
                    "Lgame/A;->x()V|0|110|1|Ljava/lang/Object;->wait()V|"
                    "Ljava/lang/Object;->wait()V")
        self.assertEqual(len(parse_lines([template.format(2), template.format(1)])), 2)

    def test_direct_file_v2_record(self):
        line = ("AGRTRACE|v2|456|457|1|Lgame/Main;->start()V|7|110|12|"
                "Landroid/app/Activity;->setContentView(I)V|"
                "Landroid/app/Activity;->setContentView(I)V")
        event = parse_lines([line], allowed_pids={456})[0]
        self.assertEqual((event["process_id"], event["thread_id"]), (456, 457))

    def test_truncated_record_fails_closed(self):
        with self.assertRaisesRegex(ValueError, "truncated"):
            parse_lines(["09-25 12:34:56.789  123  124 I dalvikvm: AGRTRACE|v1|1|broken"])

    def test_game_process_filter_excludes_other_app_events(self):
        other = ("09-25 12:34:56.789  123  124 I dalvikvm: AGRTRACE|v1|9|"
                 "Lother/Main;->start()V|7|110|12|Ljava/lang/Object;->wait()V|"
                 "Ljava/lang/Object;->wait()V")
        game = other.replace(" 123  124 ", " 456  457 ").replace("|9|", "|1|")
        events = parse_lines([other, game], allowed_pids={456})
        self.assertEqual(len(events), 1)
        self.assertEqual(events[0]["process_id"], 456)


if __name__ == "__main__":
    unittest.main()
