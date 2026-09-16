# Gameplay replay corpus

Each JSON file is an immutable candidate trace for an original APK, identified
by package and version in the test sample manifest. The runner injects one
event at a time through the guest input queue, advances a fixed number of
guest frames, and records input consumption, draw/swap deltas, Runtime import
coverage and a coarse framebuffer fingerprint. A missing input or a halted
frame loop fails the checkpoint. A changed fingerprint alone does not prove
gameplay.

`candidate_recording` traces are not certified gameplay. Promote a trace only
after the resulting frames have been inspected and a repeated CI run confirms
the same meaningful game states. The first-layer batch probe remains a smoke
screen and does not contribute to the replay verdict.
