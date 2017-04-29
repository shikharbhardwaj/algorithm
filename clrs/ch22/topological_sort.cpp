#include "../implementations/graph.hpp"
int main(){
    graph<std::string, graph_properties::list, edge_properties::directed> 
        my_graph;
    my_graph.add_vertex(std::string("hi"));
    my_graph.add_vertex(std::string("there"));
    my_graph.add_edge("hi", "there");
}
