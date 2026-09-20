#!/bin/bash
g++ -g -std=c++20 -Wall -Wextra -DLOCAL "$1".cpp -o ./bin/"$1"