#!/bin/bash

CMAKE () {
    rm -R build
    mkdir -p build
    cd build
    cmake ..
    make
    cd ..
}

CMAKE_INSTALL () {
    rm -R build
    mkdir -p build
    cd build
    cmake -D RELEASE=ON ..
    make install
    cd ..
}

CMAKE;
