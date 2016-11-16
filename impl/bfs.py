#!/usr/bin/python3
def bfs(src, adj):
	frontier = [src]
	parent = {src:None}
	level = {src:0}
	i = 0
	while frontier:
		i = i + 1
		next = []
		for cur in frontier:
			for u in adj[cur]:
				if u not in parent:
					next.append(u)
					level[u] = i
					parent[u] = cur
		frontier = next

	return parent, level

def shortest_path(u, v, adj):
	parent, level = bfs(u, adj)
	cur = v
	while cur != None:
		print(cur)
		cur = parent[cur]