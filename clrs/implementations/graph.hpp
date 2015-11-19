#include <sstream>
#include <type_traits>
#include <vector>
namespace graph_types{
    class list;
    class matrix;
}
template <typename attrib>
class vertex {
    attrib id;
    public:
    vertex(int in){
        id = in;
    }
};
template <typename attrib>
class edge {
    vertex<attrib> u, v;
};

template <class attrib, class graph_type, typename enable = void>
class graph;

template <typename attrib, class graph_type>
class graph<attrib, graph_type, 
      typename std::enable_if <std::is_same <graph_type, graph_types::list>::value>::type> {
          //This is an adjacency list representation
          private:
              std::vector<std::vector<vertex<attrib>>> adj_list;
          public:
              graph() = default;
              void input(std::istringstream &in){
                  unsigned num_vertices;
                  int cur_id;
                  in >> num_vertices;
                  adj_list.reserve(num_vertices);
                  for(unsigned i = 0;i < num_vertices;i++){
                      adj_list.push_back({});
                      while(in >> cur_id){
                          adj_list[i].push_back(cur_id);
                      }
                  }
              }
      };

template <typename attrib, class graph_type>
class graph<attrib, graph_type, 
      typename std::enable_if <std::is_same <graph_type, graph_types::matrix>::value>::type> {
          //This is an adjacency matrix representation
          private: std::vector<std::vector<vertex<attrib>>> adj_matrix;
          public:
                   graph() = default;
      };

