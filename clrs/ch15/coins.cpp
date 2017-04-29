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
  std::cin.tie(nullptr);
  std::vector<int> states;
  std::vector<int> coins;
  int T;
  std::cin>>T;
  while(T--){
    int S, N, temp;
    std::cin>>S>>N;
    states = std::vector<int>(S+1, std::numeric_limits<int>::max() - 1);
    if(N == 0){
      continue;
    }
    while(N--){
      std::cin>>temp;
      coins.push_back(temp);
    }
    int cnt = 0;
    states[0] = 0;
    for(int i = 1; i <= S; i++){ //For every state till sum S
      for(size_t j = 0; j < coins.size(); j++){ //Try every coin
        if(coins[j] <= i && states[i - coins[j]] + 1l < states[i]){
          states[i] = states[i - coins[j]] + 1;
        }
        cnt++;
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
