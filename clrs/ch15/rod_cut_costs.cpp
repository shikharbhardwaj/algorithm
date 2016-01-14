#include <iostream>
#include <vector>
//Solution for exercise 15.1-3
typedef std::vector<int> vi;
int cost;
int max_revenue_sub(int length, const vi& prices, vi& states){
  if( length <= 0 || static_cast<unsigned>(length) >= prices.size() ){
    return cost; //No cut was made
  }
  if( states[length] != -1){
    return states[length]; //Memoized
  }
  for(int i = 1 ;i <= length; i++){
    states[length] = std::max(states[length], prices[i] + max_revenue_sub(length-i, prices, states) - cost);
  }
  return states[length];
}
int max_revenue(unsigned length, const vi& prices){
  vi states(prices.size(), -1);
  return max_revenue_sub(length, prices, states);
}
int main(){
  int length;
  std::cin>>length;
  std::cin>>cost;
  vi prices(length + 1);
  vi states(length + 1, -1);
  prices[0] = 0;
  for(int i = 1; i <= length ; i++){
    std::cin>>prices[i];
  }
  //Simple bottom up O(n^2) solution
  states[0] = 0;
  states[1] = prices[1];
  for(int i = 1; i <= length; i++){
    for(int j = 1; j <= i; j++){
      states[i] = std::max(states[i], states[i-j] + prices[j] - cost);
    }
  }
  std::cout<<"\nMax possible revenue : "<<max_revenue(length, prices);
}
