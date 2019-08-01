#!/bin/bash

CMAKE () {
    rm -R build
    mkdir -p build
    cd build
    cmake ..
    make
    cd ..
}

CMAKE;
