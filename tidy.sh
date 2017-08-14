#!/bin/bash
clang-tidy -p build/compile_commands.json \
    challenge1/*.cpp \
    challenge2/*.cpp \
    challenge3/*.cpp \
    challenge4/*.cpp \
    -checks=-*,modernize-*,clang-analyzer-*,performance-*,readibility-*,misc-*,llvm-*,google-*,cert-*,bugprone-*