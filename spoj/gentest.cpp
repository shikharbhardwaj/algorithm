#include <cstdio>
#include <cstdlib>
int main(){
    int T = 1000000;
    printf("%d", T);
    while(T--){
        printf("%d\n", rand()%10000000);
    }
}
