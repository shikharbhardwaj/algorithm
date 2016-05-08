#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdio>
typedef unsigned long long ull;
ull nums[100001];
#define MAX 1000000007 //Imp : Learn how to find modular inverses
//Solution : 
//
//
//sum n = n*(n+1) / 2
//sum sum n = n*(n+1)*(n+2) / 6
//sum sum sum n = n*(n+1)*(n+2)*(n+3) / 24
//sum sum sum ...(x times)... sum n = n*(n+1)*....*(n+x) / (x+1)!
ull sums[100001];
int gcd(ull a , ull b) {
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int mod_inv(long long m){
    long long hcf = gcd(m, MAX);
    if( hcf != 1 ){
        return -1;
    }
}
int sum(int n, int times){
    long double ret = 1; //This is a problem
    if( times == 0 ){
        return 1;
    }
    if( n == 0 ){
        return 0;
    }
    for(int i = 0; i < times; i++){
        ret *= (n + i); 
        ret /= (i+1);
    }
    return (long long)round(ret) % MAX;
}
int main(){
    int N, x, T;
    ull M;
    scanf("%d", &T);
    while( T-- ){
        scanf("%d %d %llu", &N, &x, &M);
        M %= MAX;
        for(int i = 1; i <= N; i++){
            scanf("%llu", &nums[i]);
        }
        unsigned long long ans = 0;
        for(int i = x; i >= 1; i--){
            ans += (sum(M, x-i) % MAX * nums[i] % MAX) % MAX;
        }
        ans = ans % MAX;
        printf("%llu\n", ans);
    }
}

