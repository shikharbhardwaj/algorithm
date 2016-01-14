#include <iostream>
#include <algorithm>
//Aim: To find the smallest length of the LCS with
//    a hidden string
int main(){
  std::ios_base::sync_with_stdio(false);
  std::string temp;
  int T, n;
  std::cin>>T;
  while(T--){
    std::cin>>n;
    std::cin>>temp;
    int l = temp.length();
    int a = std::count(temp.begin(), temp.end(), 'a');
    int b = l - a;
    for(int i = 1; i < n; i++){
      std::cin>>temp;
      int cur_a = std::count(temp.begin(), temp.end(), 'a');
      int cur_b = l - cur_a;
      a = std::min(a, cur_a);
      b = std::min(b, cur_b);
    }
    std::cout<<std::min(a, b)<<'\n';
  }
}
