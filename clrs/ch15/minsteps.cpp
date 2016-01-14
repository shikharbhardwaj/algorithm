#include <iostream>
#include <vector>
#include <utility>
//The minimum steps to one problem
//
//Input : a number N
//Output : The minimum number of steps needed to 
//reduce the number to 1, by dividing by 2, 3, or 
//subtracting 1 from it
std::vector<int> states(1000, -1);
int min_steps(unsigned n){
  if( n <= 1){
    return 0;
  }
  if( n < states.size() ){
    if(states[n] != -1){
      return states[n];
    }
  }
  int result = 0;
  if( n%6 == 0 ){
    result =  1 + std::min(min_steps(n-1), std::min(min_steps(n/2), min_steps(n/3)));
  }
  else if( n%2 == 0 ){
    result =  1 + std::min(min_steps(n-1), min_steps(n/2));
  }
  else if( n%3 == 0 ){
    result =  1 + std::min(min_steps(n-1), min_steps(n/3));
  }
  else{
    result =  1 + min_steps(n-1);
  }
  if( n < states.size() ){
    states[n] = result;
  }
  return result;
}
int min_steps_bottom(unsigned n){
  std::vector<int> states(n+1);
  states[0] = states[1] = 0;
  for(unsigned i = 2; i <= n; i++){
    if( i%6 == 0 ){
      states[i] = 1 + std::min(states[i-1], std::min(states[i/2], states[i/3]));
    }
    else if( i%3 == 0 ){
      states[i] = 1 + std::min(states[i-1], states[i/3]);
    }
    else if( i%2 == 0 ){
      states[i] = 1 + std::min(states[i-1], states[i/2]);
    }
    else{
      states[i] = 1 + states[i-1];
    }
  }
  return states[n];
}
int main() { 
  int T, n;
  std::cin>>T;
  while(T--){
    std::cin>>n;
    std::cout<<"\nThe minimum steps : "<<min_steps_bottom(n);
  }
}
