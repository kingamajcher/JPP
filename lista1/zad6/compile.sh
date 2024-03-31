#!/bin/bash

gcc -o c_lib.o -c c_lib.c
ar -rcs libc_lib.a c_lib.o
gcc -shared -o libc_lib.so -fPIC c_lib.c
python3 test.py