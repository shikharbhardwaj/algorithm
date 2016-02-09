#include <cstdio>
#include <iostream>
//Now, work on the TLEs
typedef unsigned long long ull;
#define MAX 1000000007
#define CACHE 10000
int nums[100001]; int sums1[CACHE]; int sums2[CACHE]; int sums3[CACHE];
int sums(int n, int times){
    if( times == 0 ){
        return 1;
    }
    if( times == 1 ){
        return n % MAX;
    }
    if( n < CACHE ){
        if(times == 2){
            return sums1[n];
        }
        if( times == 3 ){
            return sums2[n];
        }
        if( times == 4 ){
            return sums3[n];
        }
    }
    ull ret = 0;
    for( int i = 1; i <= n; i++ ){
        ret += (sums(i, times-1) % MAX);
    }
    return ret % MAX;
}
void fill_sums(){
    sums1[0] = 0; sums1[1] = 1;
    sums2[0] = 0; sums2[1] = 1;
    sums3[0] = 0; sums3[1] = 1;
    for(int i = 2; i < CACHE; i++){
        sums1[i] = i + sums1[i-1];
        sums1[i] %= MAX;
    }
    for(int i = 2; i < CACHE; i++){
        sums2[i] = sums1[i] + sums1[i-1];
        sums2[i] %= MAX;
    }
    for(int i = 2; i < CACHE; i++){
        sums3[i] = sums2[i] + sums3[i-1];
        sums3[i] %= MAX;
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
            ans += (sums(M, x-i) * (ull)nums[i]) % MAX;
        }
        ans = ans % MAX;
        printf("%llu\n", ans);
    }
}
