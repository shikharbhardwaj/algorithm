#include <cstdio>
#include <random>
std::mt19937 gen;
std::uniform_int_distribution<long long> dist_l(0,1e18);
std::uniform_int_distribution<int> dist_i(0, 1e9);
int main(){
  getc(stdin);
  printf("100\n");
  for(int i = 0; i < 100; i++){
    printf("%lld %lld %d\n", dist_l(gen), dist_l(gen), dist_i(gen));
  }
}
