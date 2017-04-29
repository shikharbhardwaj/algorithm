# Breadth first search on a graph
#represented as an adjacency list
def BFS(source, adj):
    level = {source : 0} #This is a dict
    parent = {source : None} #Here is another
    i = 1
    frontier = [source]
    while frontier:
        after = []
        for u in frontier:
            for v in adj[u]:
                if v not in level:
                    print("Found node %d at %d level " % (v, i))
                    level[v] = i
                    parent[v] = u
                    after.append(v)
        frontier = after
        i += 1
    #After the loop has ended, display the findings : 
    print("\nLevels : ")
    for val in level:
        print(level[val],end=":")
    print("\nParents : ")
    for val in parent:
        print(parent[val],end=":")
    print("")
if __name__ == "__main__":
    print("Breadth first search implemented in Python")
    source = 1
    adj = {1:[2, 3], 2:[4], 3:[], 4:[]}
    BFS(source, adj)
