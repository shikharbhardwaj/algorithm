#!/usr/bin/python3
# -*- coding: utf-8 -*-

def bfs(g, src):
    level = {src: 0}
    parent = {src : None}
    i = 1
    frontier = [src]
    while frontier:
        for u in frontier:
            next = []
            for v in u.out_neighbours():
                if v not in level:
                    level[v] = i
                    parent[v] = u
                    for w in v.out_neighbours():
                        next.append(w)
        frontier = next
        i = i + 1
