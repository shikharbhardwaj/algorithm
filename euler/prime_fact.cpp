#include <iostream>
#include <cmath>
#include <cassert>
long long fact =600851475143;
bool is_prime(int in){
  if(in % 2 == 0){
    return false;
  }
  for(int i = 3; i <= sqrt(in); i += 2){
    if(in % i == 0){
      return false;
    }
  }
  return true;
}
int main(){
  for(long long i = 3; i <= sqrt(fact); i+= 2){
    while(fact % i == 0){
      fact /= i;
    }
  }
  std::cout<<"\nThe largest prime factor : "<<fact;
  assert(is_prime(fact));
  return 0;
}
