#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stack>
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
        _lists[u].erase(it);
        _in_deg[v]--;
        E--;
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
        return _lists[u].find(v) != _lists[u].end();
    }
    bool is_node(int u) { return _lists.find(u) != _lists.end(); }
    void reverse_edge(int u, int v) {
        remove_edge(u, v);
        add_edge(v, u);
    }
    std::multiset<int> &get_neighbours(int u) { return _lists[u]; }
    // void dump() { std::cout << _lists; }
    int V, E;

  private:
    std::unordered_map<int, std::multiset<int>> _lists;
};
class DFSState {
    std::set<int> visited;
    void dfs_visit(int i, UndirectedGraph &G) {
        if (visited.find(i) != visited.end())
            return;
        visited.insert(i);
        for (auto v : G.get_neighbours(i)) {
            dfs_visit(v, G);
        }
    }

  public:
    bool valid = true;
    void dfs(UndirectedGraph &G) {
        dfs_visit(1, G);
        if (visited.size() != (size_t)G.V) {
            valid = false;
        }
    }
};
// Implement Hierholzer's algorithm for Euler path construction
void make_tour(UndirectedGraph &G, DirectedGraph &result) {
    std::stack<int> cur_path;
    std::vector<int> circuit;
    int cur = 1;
    do {
        if (G.get_neighbours(cur).size() == 0) {
            circuit.push_back(cur);

            cur = cur_path.top();
            cur_path.pop();
        } else {
            cur_path.push(cur);
            int v = *G.get_neighbours(cur).begin();
            G.remove_edge(cur, v);
            cur = v;
        }
    } while (!cur_path.empty());
    for (int i = circuit.size() - 1; i > 0; i--) {
        result.add_edge(circuit[i], circuit[i - 1]);
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
    DirectedGraph result(V);
    std::vector<std::pair<int, int>> in_edges;
    for (int i = 0; i < E; i++) {
        std::cin >> u >> v;
        G.add_edge(u, v);
        in_edges.push_back({u, v});
    }
    // Checks connectivity in graph
    // DFSState check;
    // check.dfs(G);
    bool possible = true;
    for (int i = 1; i <= V; i++) {
        if (G.get_neighbours(i).size() % 2) {
            possible = false;
            break;
        }
    }
    if (possible) {
        DFSState check;
        check.dfs(G);
        if (!check.valid)
            possible = false;
    }
    if (possible) {
        make_tour(G, result);
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
