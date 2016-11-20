#!/usr/bin/python3

def bfs(u, adj):
    parent = {u: None}
    level = {u: 0}
    frontier = [u]
    i = 0
    while frontier:
        i = i + 1
        next = []
        for u in frontier:
            for v in adj[u]:
                if v not in parent:
                    print("Visit %d" % v)
                    parent[v] = u
                    level[v] = i
                    next.append(v)
        frontier = next
