#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <type_traits>
#include <unordered_map>
#include <vector>
namespace graph_lib {
namespace edge_types {
struct directed;
struct undirected;
}

template <typename id_type, typename edge_type, typename graph_type,
          typename Enable = void>
class graph;

template <typename id_type, typename edge_type>
class graph<
    id_type, edge_type, graph_type,
    typename std::enable_if<
        std::is_integral<edge_type>::value &&
        std::is_same<graph_type, graph_types::unordered>::value>::type> {
    // Unwieghted unordered edges
    std::unordered_map<id_type, std::vector<edge_type>> adj_list;
    size_t V = 0, E = 0;

  public:
    graph() = default;
    size_t num_V() const { return V; }
    size_t num_E() const { return E; }
    void add_edge(id_type id1, id_type id2) {
        assert(adj_list.find(id1) != adj_list.end());
        assert(adj_list.find(id2) != adj_list.end());
        adj_list[id1].push_back(id2);
        adj_list[id2].push_back(id1);
        E++;
    }
    void add_vertex(id_type id) {
        assert(adj_list.find(id) == adj_list.end());
        adj_list[id] = {};
        V++;
    }
};

template <typename id_type, typename edge_type, typename graph_type>
class graph<id_type, edge_type, graph_type,
            typename std::enable_if<
                std::is_integral<edge_type>::value &&
                std::is_same<graph_type, graph_types::ordered>::value>::type> {
    // Unwieghted ordered edges
    std::unordered_map<id_type, std::vector<edge_type>> adj_list;
    size_t V = 0, E = 0;

  public:
    graph() = default;
    size_t num_V() const { return V; }
    size_t num_E() const { return E; }
    void add_edge(id_type id1, id_type id2) {
        assert(adj_list.find(id1) != adj_list.end());
        adj_list[id1].push_back(id2);
        E++;
    }
    void add_vertex(id_type id) {
        assert(adj_list.find(id) == adj_list.end());
        adj_list[id] = {};
        V++;
    }
};
}
#endif
