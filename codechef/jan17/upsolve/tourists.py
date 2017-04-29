#!/usr/bin/env python3

input_graph = {}
tour_edges = {}
visited = {}

V, E = str(input()).split()
V = int(V)
E = int(E)

def add_undirected_edge(u, v):
    input_graph[u].append(v)
    input_graph[v].append(u)

for i in range(1, V + 1):
    input_graph[i] = []

for i in range(E):
    u, v = str(input()).split()
    u = int(u)
    v = int(v)
    add_undirected_edge(u, v)

def dfs_visit(i):


def dfs():


