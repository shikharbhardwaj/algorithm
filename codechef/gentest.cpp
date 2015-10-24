#define QUR 10000 
#include <iostream>
#include <cstring>
#include <random>
#include <algorithm>
int NUM;
std::random_device rd;
std::mt19937 gen(rd());
int main(int argc, char **argv){
    NUM = 0;
    if(argc > 1){
        for(unsigned int i = 0; i < strlen(argv[1]); i++){
            NUM *= 10;
            NUM += argv[1][i] - '0';
        }
    }
    std::cout<<NUM<<" "<<QUR<<"\n";
    std::uniform_int_distribution<int> dist(0,NUM-1);
    for(int i = 0;i < QUR; i++){
        int r1 = dist(gen);
        int r2 = dist(gen);
        std::cout<<(r1+r2)%2<<" "<<std::min(r1,r2)<<" "<<std::max(r1, r2);
        std::cout<<"\n";
    }
}
