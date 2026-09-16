# Public test inputs

The repository does not contain third-party APKs or game data. CI resolves the
packages in `fdroid.json` through the official F-Droid repository index,
checks each downloaded APK against the SHA-256 published by that index, and
uses the APK only as an ephemeral test input.

`App/Resources/classes.dex` and `libpocbridge.so` are project-owned minimal
bridge fixtures. They contain no third-party game code or assets.
