#!/bin/bash

project_root=~/synth/synth
include="$project_root"/include
build="$project_root"/build
outputs="$project_root"/out

mkdir -p $build $outputs

g++ -std=c++20 -I"$include" "$project_root"/src/*.cpp -o "$build"/main
"$build"/main