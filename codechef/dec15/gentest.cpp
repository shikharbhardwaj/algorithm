#include <iostream>
#include <random>
std::random_device rng;
std::mt19937 gen(rng());
std::bernoulli_distribution coin_distribution(0.5);
std::uniform_int_distribution<int> filter_dist(1, 10);
int main(){
  int T = 10;
  std::cout<<T<<"\n";
  while(T--){ 
    for(int i = 0; i < 10; i++){
      if(coin_distribution(gen) == false){
        std::cout<<"b";
      }
      else{
        std::cout<<"w";
      }
    }
    std::cout<<"\n";
    int N = filter_dist(gen);
    std::cout<<N<<"\n";
    while(N--){
      for(int i = 0; i < 10; i++){
        if(coin_distribution(gen) == false){
          std::cout<<"-";
        }
        else{
          std::cout<<"+";
        }
      }
      std::cout<<"\n";
    }
  }
}
/*
Failing testcase : 
wwwbbwbwwb
8
+--++++++-
+-+-++--+-
-++++++-++
+-+-+++++-
+++-++++--
-+++---+-+
-+--+-++++
+++-+---++
wbwbwbbwbb
9
--+--++--+
----+-+-++
--+--+--++
++----++--
-++++-+---
---+++-+--
-+-++++--+
---++++++-
--+----++-
*/
