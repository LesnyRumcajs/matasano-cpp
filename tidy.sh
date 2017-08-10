#!/bin/bash
clang-tidy -p build/compile_commands.json \
    challenge1/*.cpp \
    challenge2/*.cpp  \
    -checks=-*,modernize-*,clang-analyzer-*,performance-*,readibility-*,misc-*,llvm-*,google-*,cert-*,bugprone-*