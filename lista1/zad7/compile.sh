#!/bin/bash

export PYTHONPATH=/home/kinga/JPP/lista1/zad7:$PYTHONPATH
gcc -o test test.c zad_7.c -I/usr/include/python3.10 -lpython3.10
./test