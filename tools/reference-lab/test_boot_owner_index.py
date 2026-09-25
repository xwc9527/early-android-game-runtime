import unittest
from pathlib import Path

from boot_owner_index import class_definitions, classify_book


ROOT = Path(__file__).resolve().parents[2]


class BootOwnerIndexTest(unittest.TestCase):
    def test_class_definitions_are_not_all_type_references(self):
        descriptors = class_definitions((ROOT / "App/Resources/classes.dex").read_bytes())
        self.assertEqual(descriptors, {"Lpoc/Box;", "Lpoc/Bridge;"})

    def test_classification_keeps_unknown_owner_unresolved(self):
        book = {"dependencies": [
            {"canonical_name": "Landroid/app/Activity;->onCreate()V"},
            {"canonical_name": "Lgame/Engine;->update()V"}]}
        index = {"boot_jar_hashes": {"framework.jar": "a" * 64},
                 "classes": {"Landroid/app/Activity;": {
                     "owner_cluster": "Framework", "source_repo": "platform/frameworks/base",
                     "boot_jar": "framework.jar", "boot_jar_sha256": "a" * 64,
                     "owner_basis": "BOOT_JAR_CLASS_DEFINITION"}}}
        result = classify_book(book, index)
        self.assertEqual(result["owner_counts"], {"Framework": 1})
        self.assertEqual(result["dependencies"][1]["owner_basis"], "UNRESOLVED")


if __name__ == "__main__":
    unittest.main()
