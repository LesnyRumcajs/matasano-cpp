#!/bin/bash
clang-tidy -p build/compile_commands.json \
    challenge1/*.cpp \
    challenge2/*.cpp \
    challenge3/*.cpp \
    challenge4/*.cpp \
    challenge5/*.cpp \
    challenge6/*.cpp \
    challenge7/*.cpp \
    challenge8/*.cpp \
    challenge9/*.cpp \
    -checks=-*,modernize-*,clang-analyzer-*,performance-*,readibility-*,misc-*,llvm-*,google-*,cert-*,bugprone-*,hicpp-*,mpi-*