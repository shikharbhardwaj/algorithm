#include <stdio.h>
long long memo[10000];
long long getMaxCoins(long long in){
    if(in < 10000){
        if(memo[in] != -1){
            return memo[in];
        }
        if( in/2 + in/3 + in/4 <= in ){ //The base case of the recursion
            memo[in] = in;
            return in;
        }
        else{
            memo[in] = getMaxCoins(in/2) + getMaxCoins(in/3) + getMaxCoins(in/4);
            return memo[in];
        }
    }
    else{
        if(in / 2 + in /3 + in/4 <= in){
            return in;
        }
        else{
            return getMaxCoins(in/2) + getMaxCoins(in/3) + getMaxCoins(in/4);
        }
    }
}
int main(){
    long long in;
    int i;
    for( i = 0;i < 10000;i++){
        memo[i] = -1;
    }
    while(scanf("%lld", &in) != EOF){
        printf("%lld\n", getMaxCoins(in));
    }
}
