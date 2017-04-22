#!/usr/bin/env python3

def mystery(n):
    r = 0
    for i in range(1, n):
        for j in range(i + 1, n + 1):
            for k in range(1, j + 1):
                r += 1
    return r

def pesky(n):
    r = 0
    for i in range(1, n + 1):
        for j in range(1, i + 1):
            for k in range(j, i + j + 1):
                r += 1
    return r

def prestiferous(n):
    r = 0
    for i in range(1, n + 1):
        for j in range(1, i + 1):
            for k in range(j, i + j + 1):
                for l in range(1, i + j - k + 1):
                    r += 1
    return r

def conundrum(n):
    r = 0
    for i in range(1, n + 1):
        for j in range(i + 1, n + 1):
            for k in range(i + j - 1, n + 1):
                r += 1
    return r

def fact(n):
    r = 1
    for i in range(1, n + 1):
        r *= i
    return r
