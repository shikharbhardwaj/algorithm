#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <unordered_map>

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
std::vector<std::pair<int, int>> in_edges;
// Data for the edge classification
std::unordered_map<int, int> start_time;
std::unordered_map<int, int> end_time;
std::vector<std::pair<int, int>> fwd_edges;
std::vector<std::pair<int, int>> cross_edges;
std::set<int> remaining;
int cur_time = 0;

void dfs_visit_edges(int node, Graph &G) {
    cur_time += 1;
    start_time[node] = node;
    remaining.erase(node);
    for (auto v : G.adj_list[node]) {
        if (remaining.find(v) != remaining.end()) {
            // std::cout << "Tree edge : " << node << ", " << v << "\n";
            dfs_visit_edges(v, G);
        } else {
            if (start_time.find(v) != start_time.end()) {
                if (end_time.find(v) == end_time.end()) {
                    // std::cout << "Back edge : " << node << ", " << v << "\n";
                } else if (start_time[v] > start_time[node]) {
                    // std::cout << "Fwd  edge : " << node << ", " << v << "\n";
                    fwd_edges.push_back({node, v});
                } else {
                    // std::cout << "Cross edge : " << node << ", " << v <<
                    // "\n";
                    cross_edges.push_back({node, v});
                }
            } else {
                // std::cout << "Cross edge : " << node << ", " << v << "\n";
                cross_edges.push_back({node, v});
            }
        }
    }
    cur_time += 1;
    end_time[node] = cur_time;
}

void dfs_edges(Graph &G) {
    remaining.clear();
    for (int i = 1; i <= G.N; i++) {
        remaining.insert(i);
    }
    while (remaining.size()) {
        start_time.clear();
        end_time.clear();
        int cur = *remaining.begin();
        dfs_visit_edges(cur, G);
    }
}
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
bool is_eulerian(Graph &G) {
    // if (!is_connected(G)) {
    // return false;
    //}
    bool valid = true;
    for (int i = 1; i <= G.N; i++) {
        if (G.out_degree(i) != G.in_degree(i)) {
            valid = false;
            break;
        }
    }
    return valid;
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
    if (E >= N) {
        for (auto edge : in_edges) {
            int u = edge.first;
            int v = edge.second;
            if (G.in_degree(v) > G.out_degree(v) &&
                G.out_degree(u) > G.in_degree(u)) {
                G.reverse_edge(u, v);
            }
        }
        if (is_eulerian(G)) {
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
    } else {
        std::cout << "NO\n";
    }
}
