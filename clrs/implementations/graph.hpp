// An implementation of an undirected graph using the C++ std library
#include    <type_traits>
#include    <iostream>
#include    <unordered_map>
#include    <vector>
namespace graph_types{
    class list;
    class matrix;
}
template <typename attrib>
struct vertex {
    attrib id;
    vertex(int in){
        id = in;
    }
};

template <class attrib, class graph_type, typename enable = void>
class graph;

template <typename attrib, class graph_type>
class graph<attrib, graph_type, 
      typename std::enable_if <std::is_same <graph_type, graph_types::list>::value>::type> {
          using vtype = vertex<attrib>;
          //This is an adjacency list representation
          private:
                std::unordered_map<attrib, std::vector<attrib>> adj_list;
                std::unordered_map<attrib, vtype> vertices;
          public:
              graph() = default;
              void add_vertex(vtype v1){
                  if(adj_list.count(v1.id) == 0){
                      adj_list.insert(std::pair<attrib, std::vector<attrib>>(v1.id, {}));
                      vertices.insert(std::pair<attrib, vtype>(v1.id, v1));
                  }
              }
              void add_edge(vtype v1, vtype v2){
                  adj_list[v1.id].push_back(v2.id);
                  adj_list[v2.id].push_back(v1.id);
              }
              void BFS(attrib source){
                  for(auto vertex : adj_list[source]){
                  }
              }
              void dump(){
                  for(auto it = adj_list.begin(); it != adj_list.end(); it++){
                      std::cout<<"\nVec["<<it->first<<"]";
                      for(auto elem : it->second){
                          std::cout<<"->"<<elem;
                      }
                  }
              }
      };

template <typename attrib, class graph_type>
class graph<attrib, graph_type, 
      typename std::enable_if <std::is_same <graph_type, graph_types::matrix>::value>::type> {
          //This is an adjacency matrix representation
          private: 
              std::vector<std::vector<vertex<attrib>>> adj_matrix;
          public:
                   graph() = default;
      };

