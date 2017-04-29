#!/bin/bash
./gentest > test.in
./MMSUM < test.in > test1.out
./sum_test < test.in > test2.out
