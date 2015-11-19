#include "../implementations/graph.hpp"
int main(){
    graph<int, graph_types::list> myGraph;
    myGraph.add_edge(0, 1);
    myGraph.add_edge(0, 4);
    myGraph.add_edge(1, 2);
    myGraph.add_edge(1, 3);
    myGraph.add_edge(1, 4);
    myGraph.add_edge(2, 3);
    myGraph.add_edge(3, 4);
    myGraph.dump();
}
