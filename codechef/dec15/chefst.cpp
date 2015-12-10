#include <cstdio>
#include <cmath>
#include <algorithm>
int main(){ 
  int T;
  long long n1, n2, m, ans;
  scanf("%d", &T);
  while(T--){
    scanf("%lld %lld %lld", &n1, &n2, &m);
    if(n1 < n2){    //keep the higher number first
      ans = n1;
      n1 = n2;
      n2 = ans;
    }
    if(m >= n2){
      ans = n1 - n2;
    }
    else{
      if(m*(m+1)/2 <= n2){
        ans = n1 + n2 - m*(m+1);
      }
      else{
        m = std::min(n2, m);
        while(m != 0 && n2 != 0){
          if(n2 >= m){
            n1 -= m;
            n2 -= m;
          }
          m = n2;
        }
        ans = n1 + n2;
      }
    }
    printf("%lld\n",ans);
  }
}  
