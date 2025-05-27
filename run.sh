#!/bin/bash

if gcc -Wall Function.c main.c behavior.c -o ludo.out ; then
    ./ludo.out > output48.txt
fi