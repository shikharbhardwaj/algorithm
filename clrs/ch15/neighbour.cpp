#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> donations;
std::vector<int> states;
int max_donation(size_t i){
  if(i >= donations.size()){
    return 0;
  }
  if(states[i] == -1){
    states[i] = std::max(max_donation(i + 1), max_donation(i+2) + donations[i]);
  }
  return states[i];
}
int main(){
  donations =   { 10, 3, 2, 5, 7, 8 }; 
  int last = donations[donations.size() - 1];
  donations.pop_back();
  states = std::vector<int> (donations.size(), -1);
  std::cout<<"\n"<<max_donation(0);
  states = std::vector<int> (donations.size(), -1);
  donations.push_back(last);
  std::cout<<"\n"<<max_donation(1);
}

