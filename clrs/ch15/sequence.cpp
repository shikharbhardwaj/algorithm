#include <iostream>
#include <vector>
#include <algorithm>
//Find the longest non-decreasing sequence
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int T;
  std::cin>>T;
  while(T--){
    int N;
    std::cin>>N;
    std::vector<int> states(N, 1);
    std::vector<int> nums(N);
    for(int i = 0; i < N; i++){
      std::cin>>nums[i];
    }
    //Begin with the DP
    for(int i = 0; i < N; i++){
      for(int j = 0; j < i; j++){
        if(states[i] < states[j] + 1 && nums[j] <= nums[i]){
          states[i] = states[j] + 1;
        }
      }
    }
    std::cout<<*std::max_element(states.begin(), states.end())<<"\n";
  }
}

