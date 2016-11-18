#!/usr/bin/python3
def dfs_visit(src, adj, parent = {}):
    for v in adj[src]:
        if v not in parent:
            parent[v] = src
            dfs_visit(v, adj, parent)

def dfs(adj):
    parent = {}
    start_time = {}
    end_time = {}
    timer = 0
    V = list(adj.keys())
    for s in V:
        if s not in parent:
            parent[s] = None
            dfs_visit(s, adj, parent)
    print(parent)
