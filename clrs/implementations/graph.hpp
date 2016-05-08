// An implementation of an undirected graph using the C++ std library
#include <type_traits>
#include <iostream>
#include <unordered_map>
#include <vector>
namespace graph_properties {
class list;
class matrix;
}
namespace edge_properties {
class undirected;
class directed;
}
template <typename attrib> struct vertex {
    attrib id;
    vertex() = default;
    vertex(attrib in) : id(in) {}
};

template <typename attrib, class graph_property, class edge_property,
          typename enable = void>
class graph;

template <typename attrib, class graph_property, class edge_property>
class graph<attrib, graph_property, edge_property,
            typename std::enable_if<std::is_same<
                graph_property, graph_properties::list>::value>::type> {
    using vtype = vertex<attrib>;
    // This is an adjacency list representation
  private:
    std::unordered_map<attrib, std::vector<attrib>> adj_list;
    std::unordered_map<attrib, vtype> vertices;

  public:
    graph() = default;
    void add_vertex(vtype v1) {
        if (adj_list.count(v1.id) == 0) {
            adj_list.insert(std::pair<attrib, std::vector<attrib>>(v1.id, {}));
            vertices.insert(std::pair<attrib, vtype>(v1.id, v1));
        }
    }
    template <typename attr>
    void add_edge(
        typename std::enable_if<
            std::is_same<edge_property, edge_properties::undirected>::value,
            attr>::type id1,
        attr id2) {
        // This is an undirected graph
        std::cout << "Unirected add" << std::endl;
        adj_list[id1].push_back(id2);
        adj_list[id2].push_back(id1);
    }
    template <typename attr>
    void
    add_edge(typename std::enable_if<
                 std::is_same<edge_property, edge_properties::directed>::value,
                 attr>::type id1,
             attr id2) {
        // This is a directed graph
        // Only out edges are listed in the adjacency list
        std::cout << "Directed add" << std::endl;
        adj_list[id1].push_back(id2);
    }
    void BFS(attrib src) {
        std::unordered_map<attrib, int> level;
        std::unordered_map<attrib, attrib> parent;
        std::vector<attrib> frontier;
        std::vector<attrib> next;
        int cur_level = 1;
        frontier.push_back(src);
        while (frontier.empty() == false) {
            next = {};
            for (auto u : frontier) {
                for (auto v : adj_list[u]) {
                    if (level.count(v) ==
                        0) { // If we have not visited this node earlier
                        std::cout << "Found node " << v << " at level "
                                  << cur_level << std::endl;
                        level[v] = cur_level;
                        parent[v] = u;
                        next.push_back(v);
                    }
                }
            }
            frontier = std::move(next);
            cur_level++;
        }
    }
    bool path_exists(attrib id1, attrib id2) {
        std::unordered_map<attrib, int> level;
        std::unordered_map<attrib, attrib> parent;
        std::vector<attrib> frontier;
        std::vector<attrib> next;
        int cur_level = 1;
        frontier.push_back(id1);
        while (frontier.empty() == false) {
            next = {};
            for (auto u : frontier) {
                for (auto v : adj_list[u]) {
                    if (level.count(v) ==
                        0) { // If we have not visited this node earlier
                        if (v == id2) {
                            // Destination found
                            return true;
                        }
                        level[v] = cur_level;
                        parent[v] = u;
                        next.push_back(v);
                    }
                }
            }
            frontier = std::move(next);
            cur_level++;
        }
        return false;
    }
    vtype get_vertex(attrib id) { return vertices[id]; }
    decltype(auto) get_list(attrib id) { return adj_list[id]; }
    void dump() {
        int first = 1;
        for (auto it = adj_list.begin(); it != adj_list.end(); it++) {
            std::cout << "Adj[" << it->first << "] = [";
            for (auto elem : it->second) {
                if (first == 1) {
                    std::cout << elem;
                    first = 0;
                } else {
                    std::cout << ", " << elem;
                }
            }
            first = 1;
            std::cout << "]\n";
        }
    }
};

template <typename attrib, class graph_property>
class graph<attrib, graph_property,
            typename std::enable_if<std::is_same<
                graph_property, graph_properties::matrix>::value>::type> {
    // This is an adjacency matrix representation
  private:
    std::vector<std::vector<vertex<attrib>>> adj_matrix;

  public:
    graph() = default;
};
