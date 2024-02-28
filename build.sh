#!/bin/sh

c++ -g -c -std=c++20 -Isrc src/ustring.cpp -o ustring.o
cc -g -c -std=c11 -Isrc src/unicode.c -o unicode.o
c++ -g -c -std=c++20 -Isrc test/alloc.cpp -o alloc.o

c++ -g -o alloc alloc.o ustring.o unicode.o
