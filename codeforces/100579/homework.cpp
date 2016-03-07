#include <iostream>
#include <cmath>
int primacities[10000005];
int sieve[10000005];
bool is_perfect_power(int n){
    int test = n;
    for( int i = 2; i <= sqrt(n); i++ ){
        while( n%i == 0 ){
            n /= i;
        }
        if( n == 1 ){
            return true;
        }
        n = test;
    }
    return false;
}
void pre(){
    for( int i = 4; i < 10000005; i+=2 ){
        primacities[i] = 1;
        sieve[i] = 1;
    }
    primacities[1] = 0;
    primacities[2] = 1;
    for( int i = 3; i < 10000005; i += 2 ){
        if( sieve[i] ){
            continue;
        }
        primacities[i] = 1;
        for( int j = i * 2; j < 10000005; j += i){
            if(is_perfect_power(j)){
                primacities[j] = 1;
            }
            else{
                primacities[j] = 1 + primacities[j / i];
            }
            sieve[j] = 1;
        }
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    int T, a, b, k, num;
    pre();
    std::cin>>T;
    for( int j = 1; j <= T; j++ ){
        std::cin>>a>>b>>k;
        num = 0;
        if( k <= sqrt(b) + 1 ){
            for( int i = a; i <= b; i++ ){
                if( primacities[i] == k){
                    std::cout<<"Yes : "<<i<<std::endl;
                    num++;
                }
            }
        }
        else{
            num = 0;
        }
        std::cout<<"Case #"<<j<<": "<<num<<"\n";
    }
}

