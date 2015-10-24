#include <cstdio>
#include <cstdlib>
int main(){
    int T = 1000000;
    printf("%d\n", T);
    while(T--){
        printf("%d\n", 1+rand()%5000000);
    }
}
