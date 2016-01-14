#include <iostream>
#include <vector>
#include <bitset>
//Aim : To perform Gaussian elimination on a GF(2) 
//      find the number of free variables and answer
int filters[10][100002];
const int red = 1e9 + 7;
int pow2_mod(int pow){
  long ret = 1;
  while(pow--){
    ret = ((ret%red)*2)%red;
  }
  return ret;
}
void print(const std::vector<std::bitset<10>> &in){
  for(auto elem : in){
    int cur = 0;
    std::cout<<"[ ";
    while(cur < 10){
      std::cout<<" "<<elem[cur++]<<":";
    }
    std::cout<<"\n";
  }
}
int compute_rank(std::bitset<10> &photo, size_t m, size_t n){
  int ans = 0;
  std::vector<bool> used(m, false);
  for(size_t i = 0; i < n; i++){
    size_t j = 0;
    while( j < m && (used[j] || !filters[j][i])){
      j++;
    }
    if( j == m ) continue;
    ans++;
    used[j] = true;
    for(size_t k = 0; k < m; k++){
      if(!used[k]){
        int x = 0;
        while((filters[j][i] * x + filters[k][i]) % 2 == 1){
          x++;
        }
        for(size_t p = 0; p < n; p++){
          filters[k][p] = (filters[k][p] + filters[j][p] * x) % 2;
        }
        photo[k] = (photo[k] + photo[j] * x) % 2;
      }
    }
  }
  for( size_t i = 0; i < m; i++ ){
    if(!used[i] && photo[i]){
      return -1;
    }
  }
  return ans;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  std::bitset<10> photo;
  std::string temp;
  int T, N, m, ans, pos;
  std::cin>>T;
  while(T--){
    photo = {};
    m = 0;
    pos = 0;
    std::cin>>temp;
    for(auto ch : temp){
      if(ch == 'w'){
        photo[pos++] = 1;
      }
      else{
        photo[pos++] = 0;
      }
      m++;
    }
    std::cin>>N;
    for(int i = 0; i < N; i++){
      std::cin>>temp;
      int j = 0;
      for(auto ch : temp){
        if(ch == '+'){
          filters[j++][i] = 1;
        }
        else{
          filters[j++][i] = 0;
        }
      }
    }
    int rank = compute_rank(photo, m, N);
    if(rank == -1){
      //Inconsistent matrix
      ans = 0;
    }
    else{
      ans = pow2_mod(N - rank);
    }
    std::cout<<ans<<"\n";
  }
}
