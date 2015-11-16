#include <iostream>
#include <type_traits>
#include <vector>
namespace graph_types{
    class list;
    class matrix;
}
template <typename attrib>
class vertex {
    attrib id;
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
              graph(){
                  std::cout<<"\nThis is a list!";
              }
      };

template <typename attrib, class graph_type>
class graph<attrib, graph_type, 
      typename std::enable_if <std::is_same <graph_type, graph_types::matrix>::value>::type> {
        //This is an adjacency matrix representation
          public:
              graph(){
                  std::cout<<"\nThis is a matrix!";
              }
      };

