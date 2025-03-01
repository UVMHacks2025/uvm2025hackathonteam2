#!/usr/bin/env bash
cd "$(dirname "$0")"
cmake \
  -S . \
  -G Ninja \
  -B cmake-build-debug \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_MAKE_PROGRAM=ninja \
  -DCMAKE_C_COMPILER=clang \
  -DCMAKE_CXX_COMPILER=clang++ \

cd cmake-build-debug
cmake --build .
