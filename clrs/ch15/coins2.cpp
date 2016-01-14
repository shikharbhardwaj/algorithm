#include <iostream>
#include <vector>
#include <limits>
//A solution to the Coins problem
//
//Given a list of coins with values and the
//final sum required, find the minimum number
//of coins to get the sum.
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::vector<unsigned> states;
  std::vector<unsigned> coins;
  int T;
  std::cin>>T;
  while(T--){
    unsigned S, N, temp;
    std::cin>>S>>N;
    states = std::vector<unsigned>(S+1, std::numeric_limits<unsigned>::max() - 1);
    if(N == 0){
      continue;
    }
    while(N--){
      std::cin>>temp;
      coins.push_back(temp);
    }
    int cnt = 0;
    states[0] = 0;
    for(size_t i = 0 ; i < coins.size(); i++){
      for(size_t j = i; j <= S; j++){
        cnt++;
        if(j/coins[i] + states[j%coins[i]] < states[j]){
          states[j] = j/coins[i] + states[j%coins[i]];
        }
      }
    }
    if(states[S] != std::numeric_limits<int>::max() - 1){
      std::cout<<states[S]<<'\n';
    }
    else{
      std::cout<<"No solution\n";
    }
    std::cout<<"\nLoop ran : "<<cnt;
  }
}
