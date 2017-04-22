#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <vector>

using namespace std;

// Assuming the vertices are denoted by continuous integers
using wtype = long long;
auto LIMIT = numeric_limits<wtype>::max();
struct edge {
    int to;
    wtype weight;
};
struct graph {
    vector<vector<edge>> adj_list;
};
// Single source shortest paths on positive weighted graph
void Dijkstra(size_t source, const graph &G, vector<wtype> &dists) {
    set<pair<wtype, int>> active_vertices;
    dists.assign(G.adj_list.size(), LIMIT);
    dists[source] = 0;
    active_vertices.insert({0, source});

    while (!active_vertices.empty()) {
        // Get the nearest reachable vertex
        int where = active_vertices.begin()->second;
        wtype d = active_vertices.begin()->first;
        active_vertices.erase(active_vertices.begin());
        for (auto e : G.adj_list[where]) {
            if (dists[e.to] > d + e.weight) {
                active_vertices.erase({dists[ed.to], e.to});
                dists[ed.to] = d + e.weight;
                active_vertices.erase({dists[ed.to], e.to});
            }
        }
    }
}
