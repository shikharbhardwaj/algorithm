#!/usr/bin/env python3

numbers_input = [int(x) for x in input().split()]
n, m, d, k = numbers_input

print(n, m, d, k)

ans = d

dangerous = input()

chemicals = [set(input()) for _ in range(n)]

for mask in range(2 ** d):
    good_chemicals = 0

    new_dangerous = set()

    for i, c in enumerate(dangerous):
        if mask & (2 ** i):
            continue

        new_dangerous.add(c)

    for chemical in chemicals:
        bad = chemical.intersection(new_dangerous)
        
        if not bad:
            good_chemicals += 1
    
    if good_chemicals >= k:
        ans = min(ans, bin(mask).count('1'))

print(ans)

