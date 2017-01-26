#include <iostream>
#include <set>
#include <vector>

std::vector<std::pair<int, int>> edges;
std::vector<std::set<int>> incident_edges(100001);

int main() {
    int V, E, u, v;
    std::cin >> V >> E;
    for (int i = 0; i < E; i++) {
        std::cin >> u >> v;
        edges.push_back({u, v});
        incident_edges[u].insert(edges.size() - 1);
        incident_edges[v].insert(edges.size() - 1);
    }
}
