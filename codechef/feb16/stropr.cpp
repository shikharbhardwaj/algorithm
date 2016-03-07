#include <cstdio>
#include <iostream>
//Now, work on the TLEs
typedef unsigned long long ull;
#define MAX 1000000007
#define CACHE 10000
#define DEPTH 100
int nums[100001]; 
int sums[DEPTH][CACHE]; //This is not working out
int sum(int n, int times){
    if( n == 0 ){
        return 0;
    }
    if( times == 0 ){
        return 1;
    }
    if( times == 1 ){
        return n % MAX;
    }
    //Memo
    if( n < CACHE && times < DEPTH ){
        return sums[times-1][n];
    }
    if( times == 2 ){
        return ((((long(n) * n)/2) % MAX + n/2) % MAX);
    }
    if( times == 3 ){
        return ((ull(n) * (n+1) * (n+2))/6) % MAX;
    }
    ull ret = 0;
    for( int i = 1; i <= n; i++ ){
        ret += (sum(i, times-1) % MAX);
    }
    return ret % MAX;
}
void fill_sums(){
    //Fill the memo
    for(int i = 0; i < CACHE ; i++){
        sums[0][i] = i;
    }
    for(int i = 1 ; i < DEPTH ; i++){
        sums[i][0] = 0; sums[i][1] = 1;
        for(int j = 2; j < CACHE; j++){
            sums[i][j] = sums[i-1][j] + sums[i][j-1];
            sums[i][j] %= MAX;
        }
    }
}
int main(){
    int N, x, T;
    ull M, temp;
    scanf("%d", &T);
    fill_sums();
    while( T-- ){
        scanf("%d %d %llu", &N, &x, &M);
        M %= MAX;
        for(int i = 1; i <= N; i++){
            scanf("%llu", &temp);
            nums[i] = temp % MAX;
        }
        unsigned long long ans = 0;
        for(int i = x; i >= 1; i--){
            ans += (sum(M, x-i) * (ull)nums[i]) % MAX;
        }
        ans = ans % MAX;
        printf("%llu\n", ans);
    }
}

