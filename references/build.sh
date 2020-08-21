#!/bin/sh

clear
rm test
g++ -std=c++14 -fno-elide-constructors example.cpp -o example
./example