#include "../implementations/graph.hpp"
int main() {
  graph<int, graph_types::list> my_graph;
  my_graph.add_edge(1,2);
  my_graph.add_edge(1,3);
  my_graph.add_edge(1,6);
  my_graph.add_edge(1,7);
  my_graph.add_edge(3,2);
  my_graph.add_edge(5,2);
  my_graph.add_edge(3,4);
  my_graph.BFS(1);
  my_graph.dump();
}
