#!/usr/bin/python3
def findsteps(n):
    steps = 0
    while n != 1.0:
        if n % 2 == 0:
            n = n / 2
        else:
            n = 3 * n + 1
        steps = steps + 1
        print(n, end=" ")
    print(steps + 1)

