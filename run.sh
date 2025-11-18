#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <problem_number>"
    echo "Example: $0 16"
    exit 1
fi

number=$1
echo "Running make && ./bin/problem$number"
make -j && ./bin/problem$number