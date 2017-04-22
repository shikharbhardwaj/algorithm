#include <algorithm>
#include <iostream>
#include <set>

int main(){
  std::ios_base::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while(T--){
    std::set<std::string> first_dish;
    std::string in;
    for(int i = 0; i < 4; ++i){
      std::cin >> in;
      first_dish.insert(in);
    }
    int cnt = 0;
    for(int i = 0; i < 4; ++i){
      std::cin >> in;
      if(first_dish.find(in) != first_dish.end()){
        ++cnt;
      }
    }
    if(cnt >= 2){
      std::cout << "similar" << std::endl;
    } else{
      std::cout << "dissimilar" << std::endl;
    }
  }
}
