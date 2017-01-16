#!/usr/bin/env python3
# coding=utf-8
size_info = input().split()

N = int(size_info[0])
E = int(size_info[1])

adj_lists = {}
in_degree = {}
out_degree = {}

for i in range(N):
    in_degree[i + 1] = 0
    out_degree[i + 1] = 0

for i in range(E):
    U, V = map(int, input().split())

    if U in adj_lists:
        adj_lists[U].append(V)
    else:
        adj_lists[U] = [V]

    out_degree[U] += 1
    in_degree[V] += 1

# Find the number of SCCs
