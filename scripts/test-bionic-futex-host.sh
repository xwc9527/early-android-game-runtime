#!/usr/bin/env bash
set -euo pipefail
mkdir -p build/bionic-thread-tests
${CXX:-c++} -std=c++17 -O2 -pthread -Wall -Wextra -Werror \
  Runtime/Bionic/agr_futex_host.cpp Tests/bionic_futex_host_test.cpp \
  -o build/bionic-thread-tests/futex-host
echo 'Running bounded futex host contract'
python3 -c 'import subprocess; subprocess.run(["build/bionic-thread-tests/futex-host"], check=True, timeout=60)'
${CXX:-c++} -std=c++17 -O2 -pthread -Wall -Wextra -Werror \
  Runtime/Bionic/agr_futex_host.cpp Runtime/Bionic/agr_bionic_sync.cpp \
  Tests/bionic_sync_contract_test.cpp \
  -o build/bionic-thread-tests/bionic-sync
echo 'Running bounded KitKat sync contract'
python3 -c 'import subprocess; subprocess.run(["build/bionic-thread-tests/bionic-sync"], check=True, timeout=60)'
${CXX:-c++} -std=c++17 -O2 -pthread -Wall -Wextra -Werror \
  Runtime/Bionic/agr_bionic_tls.cpp Tests/bionic_tls_contract_test.cpp \
  -o build/bionic-thread-tests/bionic-tls
echo 'Running bounded KitKat TLS contract'
python3 -c 'import subprocess; subprocess.run(["build/bionic-thread-tests/bionic-tls"], check=True, timeout=60)'
${CXX:-c++} -std=c++17 -O2 -pthread -Wall -Wextra -Werror \
  Runtime/Bionic/agr_bionic_errno_host.cpp Tests/bionic_errno_contract_test.cpp \
  -o build/bionic-thread-tests/bionic-errno
echo 'Running bounded KitKat guest errno contract'
python3 -c 'import subprocess; subprocess.run(["build/bionic-thread-tests/bionic-errno"], check=True, timeout=60)'
