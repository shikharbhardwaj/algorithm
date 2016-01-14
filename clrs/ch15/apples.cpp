#include <iostream>
#include <vector>
int main(){
  int N, M;
  std::cin>>N>>M;
  std::vector<std::vector<int>> table(N);
  for(auto &elem : table){
    elem = std::vector<int>(M);
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      std::cin>>table[i][j];
    }
  }
  //Bottom up DP solution
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      table[i][j] += std::max(table[i-1][j], table[i-1][j-1]);
    }
  }
  std::cout<<"\nThe max : "<<table[0][0];
}
