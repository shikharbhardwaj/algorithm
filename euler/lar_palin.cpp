#include <iostream>
#include <cassert>
int rev(int in){
  int ret = 0;
  while(in >= 1){
    ret *= 10;
    ret += (in%10);
    in /= 10;
  }
  return ret;
}
bool is_palin(int in){
  int ret = rev(in);
  if(ret == in){
    return true;
  }
  return false;
}
int main(){
  int cur_max = 0;
  for(int i = 100; i < 1000; i++){
    for(int j = 100; j < 1000; j++){
      if(is_palin(i * j)){
        if(cur_max < (i * j)){
          cur_max = (i*j);
        }
      }
    }
  }
  std::cout<<"\nThe ans : "<<cur_max;
}
