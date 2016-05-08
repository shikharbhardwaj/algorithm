#include <cstdio>
int sum(int n){
    return n*(n+1)/2;
}
int sum(int n, int d){
    int cur = sum(n);
    d--;
    while( d-- ){
        cur = sum(cur);
    }
    return cur;
}
int main(){
    int T;
    scanf("%d", &T);
    while( T-- ){
        int N, D;
        scanf("%d %d", &D, &N);
        printf("%d\n", sum(N, D));
    }
}
