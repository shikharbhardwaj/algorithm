#include "../implementations/graph.hpp"
#include <iostream>
#include <vector>
#include <limits>
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int T;
  std::cin>>T;
  while(T--){
    graph<int, graph_types::list> paths;
    vertex<int> temp;
    int N, P, id1, id2;
    std::cin>>N>>P;
    std::vector<int> states(N, std::numeric_limits<int>::max() - 1);
    for(int i = 0; i < N; i++){
      //Input the graph in adjacency list
      temp.id = i;
      std::cin>>temp.weight;
      paths.add_vertex(temp);
    }
    for(int i = 0; i < P; i++){
      std::cin>>id1>>id2;
      paths.add_edge(id1, id2);
    }
    //Now we start with the shortest path algorithm
    //We need to find the shortest path from the 
    //vertex with id = 0 to id = N-1, if exists
    std::cout<<"\nWorking.. : "<<std::endl;
    states[0] = 0;
    for(int i = 1; i < N; i++){
      for(auto v : paths.get_list(i)){
        if(states[i] > states[v] + (long)paths.get_vertex(v).weight){
          states[i] = states[v] + paths.get_vertex(v).weight;
        }
      }
    }
    if(states[N-1] != std::numeric_limits<int>::max()-1){
      std::cout<<states[N-1]<<"\n";
    }
    else{
      std::cout<<"Does not exist\n";
    }
  }
}
