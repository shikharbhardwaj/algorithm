#include <cstdio>
long long costs[100001];
long long times[100001];
int main(){
    long long T, N, K, max;
    scanf("%lld", &T);
    while(T--){
        scanf("%lld", &N);
        scanf("%lld", &K);
        for(int i = 0; i < N; i++){
            scanf("%lld", &times[i]);
        }
        for(int i = 0; i < N; i++){
            scanf("%lld", &costs[i]);
        }
        max = 0;
        for(int i = 0; i < N; i++){
            if( max < (K/times[i]) * costs[i] ){
                max = (K/times[i]) * costs[i];
            }
        }
        printf("%lld\n", max);
    }
}
