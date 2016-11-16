#!/usr/bin/python3
def dfs_visit(src, adj):
	for v in adj[src]:
		if v not in dfs_visit.parent:
			dfs_visit.parent[v] = src;
			dfs_visit(v, adj)
	return dfs_visit.parent

dfs_visit.parent = {}