#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
#include <vector>

std::unordered_map<int, std::list<int>> graph;
std::unordered_map<int, int> in_deg;
std::unordered_map<int, int> start_time;
std::unordered_map<int, int> end_time;
std::vector<std::pair<int, int>> fwd_edges;
std::vector<std::pair<int, int>> cross_edges;
std::vector<std::pair<int, int>> in_edges;
std::set<int> un_visited;
int N, E, cur_time = 0;

int out_degree(int v) { return graph[v].size(); }
bool is_connected(int u, int v) {
    return std::find(graph[u].begin(), graph[u].end(), v) != graph[u].end();
}
void reverse(int u, int v) {
    auto &adj_list = graph[u];
    adj_list.erase(std::remove(adj_list.begin(), adj_list.end(), v),
                   adj_list.end());
    graph[v].push_back(u);
    in_deg[v] -= 1;
    in_deg[u] += 1;
}
void dfs_visit_edges(int node) {
    // We need to visit this
    cur_time += 1;
    start_time[node] = cur_time;
    un_visited.erase(node);
    for (auto v : graph[node]) {
        if (un_visited.find(v) != un_visited.end()) {
            // std::cout << "Tree edge : " << node << ", " << v << "\n";
            dfs_visit_edges(v);
        } else {
            if (end_time.find(v) == end_time.end() &&
                start_time.find(v) != start_time.end()) {
                // std::cout << "Back edge : " << node << ", " << v << '\n';
            } else if (start_time.find(v) != start_time.end()) {
                // std::cout << "Fwd  edge : " << node << ", " << v << "\n";
                fwd_edges.push_back({node, v});
            } else {
                // std::cout << "Cross edge : " << node << ", " << v << "\n";
                cross_edges.push_back({node, v});
            }
        }
    }
    cur_time += 1;
    end_time[node] = cur_time;
}
void dfs_edges() {
    for (int i = 1; i <= N; i++) {
        un_visited.insert(i);
    }
    while (un_visited.size() != 0) {
        start_time.clear();
        end_time.clear();
        int cur = *un_visited.begin();
        dfs_visit_edges(cur);
    }
}
void dfs_visit(int node) {
    un_visited.erase(node);
    auto i = graph[node].begin();
    while (i != graph[node].end()) {
        if (un_visited.find(*i) != un_visited.end()) {
            dfs_visit(*i);
        }
        i++;
    }
}
void dfs() {
    un_visited.clear();
    for (int i = 0; i < N; ++i) {
        un_visited.insert(i + 1);
    }
    int cur = *un_visited.begin();
    dfs_visit(cur);
}
bool is_connected() {
    dfs();
    if (un_visited.size()) {
        return false;
    }
    std::unordered_map<int, std::list<int>> transpose;
    for (int i = 1; i <= N; i++) {
        auto it = graph[i].begin();
        while (it != graph[i].end()) {
            if (transpose.find(*it) != transpose.end()) {
                transpose[*it].push_back(i);
            } else {
                transpose[*it] = {i};
            }
            it++;
        }
    }
    graph = transpose;
    dfs();
    if (un_visited.size()) {
        return false;
    }
    return true;
}
bool is_eulerian() {
    if (!is_connected()) {
        return false;
    }
    bool valid = true;
    for (int i = 1; i <= N; i++) {
        if (graph[i].size() != (size_t)in_deg[i]) {
            valid = false;
            break;
        }
    }
    return valid;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> N >> E;
    for (int i = 1; i <= N; i++) {
        in_deg[i] = 0;
    }
    for (int i = 0; i < E; i++) {
        int U, V;
        std::cin >> U >> V;
        if (graph.find(U) != graph.end()) {
            graph[U].push_back(V);
        } else {
            graph[U] = {V};
        }
        in_deg[V] += 1;
        in_edges.push_back({U, V});
    }
    dfs_edges();
    for (auto edge : fwd_edges) {
        int u = edge.first;
        int v = edge.second;
        if (!is_connected(v, u)) {
            reverse(u, v);
        }
    }
    for (auto edge : cross_edges) {
        int u = edge.first;
        int v = edge.second;
    }
    if (is_eulerian()) {
        std::cout << "YES\n";
        for (auto elem : in_edges) {
            int U = elem.first;
            int V = elem.second;
            if (std::find(graph[U].begin(), graph[U].end(), V) ==
                graph[U].end()) {
                std::cout << V << " " << U << "\n";
            } else {
                std::cout << U << " " << V << "\n";
            }
        }
    } else {
        std::cout << "NO\n";
    }
}
