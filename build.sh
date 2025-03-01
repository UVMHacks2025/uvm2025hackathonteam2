#!/usr/bin/env bash
cd "$(dirname "$0")"
cmake \
  -S . \
  -B build \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_C_COMPILER=clang \
  -DCMAKE_CXX_COMPILER=clang++

cd build
cmake --build .

if [[ $1 = "run" ]]; then
  exec ./hack
fi
