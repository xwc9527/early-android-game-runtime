import unittest

from probe_pair import guest_data_space


class GuestDataSpaceTest(unittest.TestCase):
    def test_api19_df_capacity_and_free_space(self):
        output = ("Filesystem               Size     Used     Free   Blksize\n"
                  "/data                  197.0M     6.2M   190.8M   4096\n")
        result = guest_data_space(output)
        self.assertEqual(result["total_mb"], 197.0)
        self.assertEqual(result["free_mb"], 190.8)

    def test_unknown_df_fails_closed(self):
        with self.assertRaisesRegex(RuntimeError, "unrecognized guest df unit"):
            guest_data_space("/data 100 10 90 4096")


if __name__ == "__main__":
    unittest.main()
