#!/usr/bin/python3
def main():
    T = int(input())
    for i in range(T):
        s,v = (input().split())
        s = float(s)
        v = float(v)
        print(2 * s / ( 3 * v ))

main()

