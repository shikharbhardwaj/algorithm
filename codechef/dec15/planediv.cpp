#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
int gcd(int a, int b){
  return (b == 0)? a : gcd(b, a%b);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  int T, a, b, n;
  float c;
  std::cin>>T;
  std::map<std::pair<int, int>, std::set<double>> eqs;
  while(T--){
    eqs = {};
    std::cin>>n;
    for(int i = 0; i < n; i++){
      std::cin>>a>>b>>c;
      int div = gcd(a, b);
      a /= div;
      b /= div;
      c = (float)c/div;
      eqs[std::make_pair(a, b)].insert(c);
    }
    size_t ans = 0;
    for(auto elem : eqs){
      if(elem.second.size() > ans){
        ans = elem.second.size();
      }
    }
    std::cout<<ans<<"\n";
  }
}
