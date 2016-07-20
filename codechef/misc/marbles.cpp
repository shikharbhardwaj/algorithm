//Problem : Marbles | Codechef, Medium
#include <cstdio>
#include <cmath>
using ull = unsigned long long;
ull compute(ull n, ull k){
    long double res = 1;
    for(long long i = 1; i < k ; i++){
        res *= n-i;
        res /= k-i;
    }
    return round(res);
}
int main(){
    int T;
    ull n, k;
    scanf("%d", &T);
    while(T--){
        scanf("%llu%llu", &n, &k);
        printf("%llu\n", compute(n,k));
    }
}
