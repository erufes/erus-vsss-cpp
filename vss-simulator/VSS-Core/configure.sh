#!/bin/bash

CMAKE () {
    bash scripts/protos.sh
    rm -R build
    mkdir -p build
    cd build
    cmake ..
    make
    cd ..
}

CMAKE;
