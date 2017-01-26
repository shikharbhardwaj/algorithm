#include <algorithm>
#include <iostream>
#include <list>
#include <map>
//#include <prettyprint/prettyprint.hpp>
#include <set>
#include <unordered_map>

std::vector<std::pair<int, int>> in_edges;

struct Graph {
    std::unordered_map<int, std::list<int>> adj_list;
    std::unordered_map<int, int> in_deg;
    int N, E;

    Graph(int _n, int _e) : N(_n), E(_e) {
        for (int i = 1; i <= N; i++) {
            in_deg[i] = 0;
        }
    }
    int out_degree(int U) { return adj_list[U].size(); }
    int in_degree(int U) { return in_deg[U]; }
    void add_edge(int U, int V) {
        if (adj_list.find(U) != adj_list.end()) {
            adj_list[U].push_back(V);
        } else {
            adj_list[U] = {V};
        }
        in_deg[V] += 1;
    }
    void remove_edge(int U, int V) {
        adj_list[U].remove_if([V](int n) { return n == V; });
        in_deg[V] -= 1;
    }
    bool is_connected(int U, int V) {
        return std::find(adj_list[U].begin(), adj_list[U].end(), V) !=
               adj_list[U].end();
    }
    void reverse_edge(int U, int V) {
        remove_edge(U, V);
        add_edge(V, U);
    }
    void dump() {
        for (int i = 1; i <= N; i++) {
            for (auto v : adj_list[i]) {
                std::cout << i << ' ' << v << '\n';
            }
        }
    }
};

std::set<int> remaining;
std::unordered_map<int, int> start_time;
std::unordered_map<int, int> end_time;
void dfs_visit(int node, Graph &G) {
    remaining.erase(node);
    for (auto v : G.adj_list[node]) {
        if (remaining.find(v) != remaining.end()) {
            dfs_visit(v, G);
        }
    }
}
void dfs(Graph &G) {
    remaining.clear();
    start_time.clear();
    end_time.clear();
    for (int i = 1; i <= G.N; i++) {
        remaining.insert(i);
    }
    dfs_visit(*remaining.begin(), G);
}
bool is_connected(Graph &G) {
    dfs(G);
    if (remaining.size()) {
        return false;
    }
    Graph transpose = G;
    for (int i = 1; i <= G.N; i++) {
        auto it = G.adj_list[i].begin();
        while (it != G.adj_list[i].end()) {
            if (transpose.adj_list.find(*it) != transpose.adj_list.end()) {
                transpose.adj_list[*it].push_back(i);
            } else {
                transpose.adj_list[*it] = {i};
            }
            it++;
        }
    }
    dfs(transpose);
    if (remaining.size()) {
        return false;
    }
    return true;
}
bool possible(Graph &G) {
    std::set<int, int> unbalanced;
    for (int i = G.N; i >= 1; i--) {
        if ((G.out_degree(i) + G.in_degree(i)) % 2) {
            return false;
        }
        if (G.in_degree(i) != G.out_degree(i)) {
            unbalanced.insert(i);
        }
    }
    if (unbalanced.size() % 2) {
        return false;
    }
    auto it = unbalanced.begin();
    int cur = 2;
    while (true) {
        int u = *it;
        if (G.out_degree(u) - G.in_degree(u) == cur) {
            for (auto v : unbalanced) {
            }
        }
    }
    return true && is_connected(G);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    int N, E;
    std::cin >> N >> E;
    Graph G(N, E);
    for (int i = 0; i < E; i++) {
        int U, V;
        std::cin >> U >> V;
        G.add_edge(U, V);
        in_edges.push_back({U, V});
    }
    if (possible(G)) {
        std::cout << "YES\n";
        for (auto elem : in_edges) {
            int U = elem.first;
            int V = elem.second;
            if (G.is_connected(U, V)) {
                std::cout << U << " " << V << "\n";
            } else {
                std::cout << V << " " << U << "\n";
            }
        }
    } else {
        std::cout << "NO\n";
    }
}
