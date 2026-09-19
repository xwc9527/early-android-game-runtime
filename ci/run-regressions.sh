#!/bin/bash
set -euo pipefail
exec python3 ci/run-suite.py regressions --satisfied simulator-build
