import tempfile
import unittest
import zipfile
from pathlib import Path

from preload_inventory import preload_inventory


class PreloadInventoryTest(unittest.TestCase):
    def test_only_complete_matching_zygote_log_proves_preload(self):
        with tempfile.TemporaryDirectory() as tmp:
            jar = Path(tmp) / "framework.jar"
            with zipfile.ZipFile(jar, "w") as archive:
                archive.writestr("preloaded-classes", "# comment\nandroid.app.Activity\njava.lang.String\n")
            proven = preload_inventory(jar, "I Zygote: ...preloaded 2 classes in 12ms.")
            self.assertEqual(proven["class_state"], "PRELOADED_IN_ZYGOTE")
            self.assertEqual(proven["preloaded_classes"],
                             ["android.app.Activity", "java.lang.String"])
            incomplete = preload_inventory(jar, "I Zygote: ...preloaded 1 classes in 12ms.")
            self.assertEqual(incomplete["class_state"], "PRELOAD_CONFIGURED_ONLY")
            failed = preload_inventory(jar, "Class not found for preloading: java.lang.String\n"
                                              "...preloaded 1 classes in 12ms.")
            self.assertEqual(failed["class_state"], "PRELOADED_IN_ZYGOTE")
            self.assertEqual(failed["preloaded_classes"], ["android.app.Activity"])


if __name__ == "__main__":
    unittest.main()
