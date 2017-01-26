#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
class DirectedGraph {
  public:
    DirectedGraph() = default;
    DirectedGraph(int v) : V(v) {
        for (int i = 1; i <= V; i++) {
            add_node(i);
        }
    }
    void add_node(int u) {
        _lists[u] = {};
        _in_deg[u] = 0;
    }
    void add_edge(int u, int v) {
        _lists[u].insert(v);
        _in_deg[v]++;
        E++;
    }
    void remove_edge(int u, int v) {
        auto it = _lists[u].find(v);
        if (it != _lists[u].end()) {
            _lists[u].erase(it);
            _in_deg[v]--;
            E--;
        }
    }
    bool is_connected(int u, int v) {
        return _lists[u].find(v) != _lists[u].end();
    }
    bool is_node(int u) { return _lists.find(u) != _lists.end(); }
    void reverse_edge(int u, int v) {
        remove_edge(u, v);
        add_edge(v, u);
    }
    std::set<int> &get_neighbours(int u) { return _lists[u]; }
    int V, E;

  private:
    std::unordered_map<int, std::set<int>> _lists;
    std::unordered_map<int, int> _in_deg;
};
class UndirectedGraph {
  public:
    UndirectedGraph() = default;
    UndirectedGraph(int v) : V(v) {
        for (int i = 1; i <= V; i++) {
            add_node(i);
        }
    }
    void add_node(int u) { _lists[u] = {}; }
    void add_edge(int u, int v) {
        _lists[u].insert(v);
        _lists[v].insert(u);
        E++;
    }
    void remove_edge(int u, int v) {
        auto it = _lists[u].find(v);
        _lists[u].erase(it);
        it = _lists[v].find(u);
        _lists[v].erase(it);
        E--;
    }
    bool is_connected(int u, int v) {
        return _lists[v].find(v) != _lists[u].end();
    }
    bool is_node(int u) { return _lists.find(u) != _lists.end(); }
    void reverse_edge(int u, int v) {
        remove_edge(u, v);
        add_edge(v, u);
    }
    std::multiset<int> &get_neighbours(int u) { return _lists[u]; }
    int V, E;

  private:
    std::unordered_map<int, std::multiset<int>> _lists;
};
class DFSState {
    std::unordered_map<int, bool> visited;
    void dfs_visit(int i, UndirectedGraph &G) {
        visited[i] = true;
        for (auto v : G.get_neighbours(i)) {
            if (!visited[v]) {
                dfs_visit(v, G);
            }
        }
    }

  public:
    bool valid = true;
    void dfs(UndirectedGraph &G) {
        for (int i = 1; i <= G.V; i++) {
            visited[i] = false;
            if (G.get_neighbours(i).size() % 2) {
                valid = false;
                return;
            }
        }
        dfs_visit(1, G);
        for (auto node : visited) {
            if (node.second == false) {
                valid = false;
            }
        }
    }
};
// Implement Hierholzer's algorithm for Euler path construction
std::set<int> visited;
void make_tour(int u, UndirectedGraph &G, DirectedGraph &result) {
    visited.insert(u);
    while (!G.get_neighbours(u).empty()) {
        int v = *G.get_neighbours(u).begin();
        G.remove_edge(u, v);
        result.add_edge(u, v);
        make_tour(v, G, result);
    }
}
int main() {
    // if (std::freopen("test.in", "r", stdin) == 0) {
    // return 1;
    //}
    std::ios_base::sync_with_stdio(false);
    int V, E, u, v;
    std::cin >> V >> E;
    UndirectedGraph G(V);
    std::vector<std::pair<int, int>> in_edges;
    for (int i = 0; i < E; i++) {
        std::cin >> u >> v;
        G.add_edge(u, v);
        in_edges.push_back({u, v});
    }
    bool valid = true;
    for (int i = 1; i <= V && valid; ++i) {
        if (G.get_neighbours(i).size() % 2)
            valid = false;
    }
    DirectedGraph result(V);
    if (valid)
        make_tour(1, G, result);
    if (valid && visited.size() == (size_t)V) {
        // DFSState check;
        // check.dfs(G);
        std::cout << "YES\n";
        for (auto edge : in_edges) {
            if (result.is_connected(edge.first, edge.second)) {
                std::cout << edge.first << " " << edge.second << '\n';
            } else {
                std::cout << edge.second << " " << edge.first << '\n';
            }
        }
    } else {
        std::cout << "NO\n";
    }
}
