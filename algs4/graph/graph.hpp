#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
class Graph {
  public:
    Graph(int v) {
        V = v;
        E = 0;
        adj_list.assign(V, {});
    }
    Graph(std::istream &stream) {
        int v, w;
        stream >> V >> E;
        adj_list.assign(V, {});
        for (size_t i = 0; i < E; i++) {
            stream >> w >> v;
            add_edge(w, v);
        }
    }
    int num_V() const { return V; }
    int num_E() const { return E; }
    void add_edge(int v, int w) {
        adj_list[v].push_back(w);
        adj_list[w].push_back(v);
        E++;
    }
    std::vector<size_t> adj(int v) const { return adj_list[v]; }
    std::vector<size_t> &adj(int v) { return adj_list[v]; }
    std::string to_string() {
        std::string out;
        out = "Graph instance with " + std::to_string(V) + " vertices and " +
              std::to_string(E) + " edges\n";
        return out;
    }
    size_t degree(int v) { return adj_list[v].size(); }
    size_t max_degree() {
        size_t max = 0;
        for (auto elem : adj_list) {
            if (elem.size() > max) {
                max = elem.size();
            }
        }
        return max;
    }
    int num_self_loops() {
        int cnt = 0;
        for (size_t i = 0; i < adj_list.size(); i++) {
            for (auto w : adj_list[i]) {
                if (w == i) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

  private:
    std::vector<std::vector<size_t>> adj_list;
    size_t V, E;
};
void BFS_single_source(const Graph &G, size_t s,
                       std::vector<size_t> &connected) {
    std::vector<size_t> frontier = {s};
    std::vector<bool> visited(G.num_V(), false);
    while (frontier.size()) {
        std::vector<size_t> next;
        for (auto elem : frontier) {
            if (!visited[elem]) {
                visited[elem] = true;
                auto adj = G.adj(elem);
                std::copy(adj.begin(), adj.end(), std::back_inserter(next));
                std::copy(adj.begin(), adj.end(),
                          std::back_inserter(connected));
            }
        }
        frontier = next;
    }
}
