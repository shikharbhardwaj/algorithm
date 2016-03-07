#include <cstdio>
#include <cstdlib>
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dist(1, 5000000);
int main(int argc, char **argv){
    int T = 125000;
    if ( argc > 1 ){
        T = atoi(argv[argc-1]);
    }
    printf("%d\n", T);
    while(T--){
        printf("%d\n", dist(gen));
    }
}
