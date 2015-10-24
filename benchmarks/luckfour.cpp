#include <cstdio>
int numFour(int in){
    int  cnt = 0;
    while(in > 1){
        if(in%10 == 4){
            cnt++;
        }
        in/=10;
    }
    return cnt;
}
int main(){
    int T;
    scanf("%d", &T);
    int in;
    while(T--){
        scanf("%d", &in);
        printf("%d\n", numFour(in));
    }
    return 0;
}
