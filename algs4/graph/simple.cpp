#include "graph.hpp"
int main() {
    Graph G(5);
    G.add_edge(1, 0);
    std::cout << std::boolalpha << is_connected(G, 1, 0);
}
