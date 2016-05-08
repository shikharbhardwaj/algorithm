#include <iostream>
#include <vector>
//Aim : To perform Gaussian elimination on a GF(2) 
//      find the number of free variables and answer
const int red = 1e9 + 7;
long long pow2_mod(int pow){
  long long ret = 1;
  while(pow--){
    ret = ((ret%red)*2)%red;
  } return ret; }
void print(const std::vector<std::vector<long long>> &in){
  for(auto elem : in){
    std::cout<<"[ ";
    for(auto cont : elem){
      std::cout<<" "<<cont<<":";
    }
    std::cout<<"\n";
  }
}
int main(){
  std::ios_base::sync_with_stdio(false);
  std::vector<long long int>              photo;
  std::vector<std::vector<long long int>> filters;
  std::vector<std::vector<long long int>> matrix;
  long long ans = 0;
  char ch;
  int T, N;
  std::cin>>T;
  std::cin.ignore();
  while(T--){
    filters = {};
    photo = {};
    matrix = {};
    while((ch = std::cin.get()) != '\n'){
      if(ch == 'w'){
        photo.push_back(1);
      }
      else{
        photo.push_back(0);
      }
    }
    std::cin>>N;
    std::cin.ignore();
    filters.reserve(N);
    for(int i = 0; i < N; i++){
      filters.push_back({});
      while((ch = std::cin.get()) != '\n'){
        if(ch == '+'){
          filters[i].push_back(1);
        }
        else{
          filters[i].push_back(0);
        }
      }
    }
    //Constructing matrix
    for(size_t i = 0; i < filters[0].size(); i++){
      matrix.push_back({});
      for(int j = 0; j < N; j++){
        matrix[i].push_back(filters[j][i]);
      }
      matrix[i].push_back(photo[i]);
    }
    print(matrix);
    std::cout<<"\nhuh";
    //Gaussian elimination on GF(2)
    long long last_pivot = -1;
    auto n = matrix.size();
    auto m = matrix[0].size();
    for(size_t i = 0; i < n; i++){
      for(size_t j = 0; j < m-1; j++){
        if(matrix[i][j] != 0){
          last_pivot = j;
          for(size_t k = 0; k < n; k++){
            if(k == i){
              continue;
            }
            if(matrix[k][j] != 0){
              for(size_t t = 0; t < m; t++){
                matrix[k][t] ^= matrix[i][t];
              }
            }
          }
          break;
        }
      }
    }
    print(matrix);
    bool flag = false;
    for(auto row : matrix){
      if(row[row.size()-1] != 0){
        for(size_t j = 0; row[j] == 0; j++){
          if(j == row.size()-2){
            flag = true;
            break;
          }
        }
        if(flag){
          ans = 0;
        }
      }
    }
    if(!flag){
      ans =  pow2_mod(filters.size() - (last_pivot + 1));
      ans %= red;
    }
    std::cout<<ans<<"\n";
  }
}
