#! /bin/bash
set -ex

WORKDIR="build"

ROOTDIR="$(pwd)"
mkdir -p "${WORKDIR}"
cd "${WORKDIR}"

exec cmake "${ROOTDIR}" \
           -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
           -DCMAKE_CXX_FLAGS="-fdiagnostics-color=always" \
           -DCMAKE_EXPORT_COMPILE_COMMANDS="ON" \
           -GNinja

