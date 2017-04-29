#include <iostream>
#include <random>
#include <algorithm>
#include <cassert>
std::random_device rng;
std::mt19937 mt(rng());
int main(){
    int* ar = new int[1000000];
    std::uniform_int_distribution<int> dist;
    for(int i = 0;i < 1000000; i++){
        ar[i] = dist(rng);
    }
    std::sort(ar, ar + 1000000);
    assert(std::is_sorted(ar, ar + 1000000));
    delete[] ar;
}
