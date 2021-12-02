#!/bin/sh

cd $(dirname $0)

sed 's/\"\S*g++/"\/usr\/lib\/g++ -std=c++20/' $1/compile_commands.json  > ./compile_commands.json
