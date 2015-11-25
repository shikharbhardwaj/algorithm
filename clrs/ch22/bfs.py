# Breadth first search on a graph
#represented as an adjacency list
def BFS(source, adj):
    level = {source : 0} #This is a dict
    parent = {source : None} #Here is another
    i = 1
    frontier = [source]
    while frontier:
        next = []
        for u in frontier:
            for v in adj[u]:
                if v not in level:
                    print("Found node %d at %d level " % (v, i))
                    level[v] = i
                    parent[v] = u
                    next.append(v)
        frontier = next
        i += 1
    #After the loop has ended, display the findings : 
    print("\nLevels : ")
    for val in level:
        print(level[val],end=":")
    print("\nParents : ")
    for val in parent:
        print(parent[val],end=":")
    print("")

def fact(inp):
    if inp == 1:
        return 1
    return inp*fact(inp-1);
