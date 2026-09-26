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
${CC:-cc} -std=c11 -O2 -Wall -Wextra -Werror \
  -c Runtime/Bionic/agr_bionic_clock.c \
  -o build/bionic-thread-tests/bionic-clock.o
${CXX:-c++} -std=c++17 -O2 -Wall -Wextra -Werror \
  build/bionic-thread-tests/bionic-clock.o \
  Runtime/Bionic/agr_bionic_errno_host.cpp Tests/bionic_clock_contract_test.cpp \
  -o build/bionic-thread-tests/bionic-clock
echo 'Running authorized realtime and monotonic Bionic clock contract'
python3 -c 'import subprocess; subprocess.run(["build/bionic-thread-tests/bionic-clock"], check=True, timeout=60)'
python3 -c 'import subprocess; subprocess.run(["build/bionic-thread-tests/bionic-errno"], check=True, timeout=60)'
${CC:-cc} -std=c11 -O2 -Wall -Wextra -Werror \
  Runtime/Bionic/agr_bionic_thread_attr.c Tests/bionic_thread_attr_contract.c \
  -o build/bionic-thread-tests/bionic-thread-attr
echo 'Running bounded KitKat ARM32 pthread attr and stack-layout contract'
python3 -c 'import subprocess; subprocess.run(["build/bionic-thread-tests/bionic-thread-attr"], check=True, timeout=60)'
${CC:-cc} -std=c11 -O2 -pthread -Wall -Wextra -Werror \
  -c Runtime/HostServices/agr_host_services_darwin.c \
  -o build/bionic-thread-tests/darwin-host-services.o
${CC:-cc} -std=c11 -O2 -Wall -Wextra -Werror \
  -c Runtime/Bionic/agr_bionic_thread_attr.c \
  -o build/bionic-thread-tests/bionic-thread-attr.o
rustup target add "$(rustc -vV | sed -n 's/^host: //p')"
cargo build --manifest-path Runtime/ArmInterpreter/Cargo.toml --release
${CXX:-c++} -std=c++17 -O2 -pthread -Wall -Wextra -Werror \
  build/bionic-thread-tests/darwin-host-services.o \
  build/bionic-thread-tests/bionic-thread-attr.o \
  Runtime/Bionic/agr_bionic_errno_host.cpp \
  Runtime/Bionic/agr_bionic_thread_lifecycle.cpp \
  Tests/bionic_thread_lifecycle_contract.cpp \
  Runtime/ArmInterpreter/target/release/libtouchhle_arm_interpreter.a \
  -framework CoreFoundation -framework Security \
  -o build/bionic-thread-tests/bionic-thread-lifecycle
echo 'Running bounded KitKat pthread lifecycle 100k create/join stress'
python3 -c 'import subprocess; subprocess.run(["build/bionic-thread-tests/bionic-thread-lifecycle"], check=True, timeout=120)'
