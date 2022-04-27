#!/bin/bash

echo "Running Test..."

gcc mem_alloc.c

./a.out < test_case.txt