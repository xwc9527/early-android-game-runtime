import unittest

from probe_pair import app_crash_lines


class ProbeRuntimeTest(unittest.TestCase):
    def test_only_game_crashes_count(self):
        log = ("09-25 01:00:00.000  20  20 E AndroidRuntime: Process: other.app, PID: 20\n"
               "09-25 01:00:01.000  42  42 F libc: Fatal signal 11\n"
               "09-25 01:00:02.000  80  80 E AndroidRuntime: Process: game.app, PID: 80\n")
        found = app_crash_lines(log, "game.app", {42, 80})
        self.assertEqual(len(found), 2)


if __name__ == "__main__":
    unittest.main()
