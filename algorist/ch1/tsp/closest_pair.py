#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math

vertex_chains = set()
vertices = []

N = int(input())
for i in range(1, N +1):
    vertex_chains.add({i})

for i in range(N):
    x, y = str(input()).split()
    x = float(x)
    y = float(y)
    vertices.append((x, y))

for i in range(N - 1):
    d = math.inf
