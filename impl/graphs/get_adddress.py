#!/usr/bin/python3
def get_address(i, n, B, el):
    offset = i[0]
    n = len(i)
    for j in range(n - 1):
        offset = offset * (n - j - 1)
        offset = offset + i[j + 1]
    return B + offset * el
