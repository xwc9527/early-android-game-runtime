#!/usr/bin/env bash
set -euo pipefail
mkdir -p build/bionic-thread-tests
${CXX:-c++} -std=c++17 -O2 -pthread -Wall -Wextra -Werror \
  Runtime/Bionic/agr_futex_host.cpp Tests/bionic_futex_host_test.cpp \
  -o build/bionic-thread-tests/futex-host
build/bionic-thread-tests/futex-host
${CXX:-c++} -std=c++17 -O2 -pthread -Wall -Wextra -Werror \
  Runtime/Bionic/agr_futex_host.cpp Runtime/Bionic/agr_bionic_sync.cpp \
  Tests/bionic_sync_contract_test.cpp \
  -o build/bionic-thread-tests/bionic-sync
build/bionic-thread-tests/bionic-sync
