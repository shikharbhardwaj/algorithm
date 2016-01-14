#include <iostream>
#include <algorithm>
#include <vector>
typedef std::vector<int> vi;
int max_revenue(int length, const vi& prices, vi& states, int cost){
  if(length <= 0 || static_cast<unsigned>(length) >= states.size()){
    return cost;
  }
  if(states[length] != -1){
    return states[length];
  }
  for(int i = 1; i <= length; i++){
    states[length] = std::max(states[length], prices[i] + max_revenue(length-i, prices, states, cost) - cost);
  }
  return states[length];
}
int main(){
  int length, cost; 
  std::cin>>length;
  std::cin>>cost;
  vi states(length+1, -1);
  vi prices(length+1, 0);
  for(int i = 1;i <= length;i++){
    std::cin>>prices[i];
  }
  states[0] = 0;
  states[1] = prices[1]; //Only needed when cost is there
  for(int i = 1; i <= length; i++){
    for(int j = 1; j <= i; j++){
      states[i] = std::max(states[i], prices[j] + states[i-j] - cost);
    }
  }
  std::cout<<"\nMax revenue : "<<states[length];
}

