#include <iostream>
int fib(int n){
  if(n == 1 || n == 2){
    return 1;
  }
  return fib(n-1) + fib(n-2);
}
int main(){
  int ans = 0;
  int i = 1;
  int cur;
  while(true){
    cur = fib(i);
    if(cur > 4000000){
      break;
    }
    if(cur%2 == 0){
      ans += cur;
    }
    i++;
  }
  std::cout<<"\nThe ans : "<<ans;
}
