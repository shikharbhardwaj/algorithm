#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
int steps[1000003];
bool is_prime(int in) {
    if( in <= 1 ){
        return false;
    }
    if( in == 2 ){
        return true;
    }
    if( in%2 == 0 ){
        return false;
    }
    int limit = sqrt(in) + 1;
    for (int i = 3; i <= limit; i += 2){
        if( in%i == 0 ){
            return false;
        }
    }
    return true;
}
int min_steps(int n){
    if( n == 0 ){
        return 0;
    }
    if(steps[n] != -1){
        return steps[n];
    }
    if( n <= 2 ){
        return 1;
    }
    if( is_prime(n) ){
        return 1;
    }
    int num = n;
    std::vector<int> factors;
    if( n%2 == 0 ) {
        while( n%2 == 0 ){
            n /= 2;
        }
        factors.push_back(2);
    }
    for (int i = 3; i <= sqrt(n); i = i+2) {
        if (n%i == 0){
            while (n%i == 0) {
                n /= i;
            }
            factors.push_back(i);
        }
    }
    if( n > 2 ){
        factors.push_back(n);
    }
    long try_steps = std::numeric_limits<int>::max();
    int cur_steps;
    for( int i = factors.size() - 1; i >= 0 ; i--){
        if(num - factors[i] > 0){
            cur_steps = min_steps(num - factors[i]);
            if(cur_steps < try_steps) {
                try_steps = cur_steps;
            }
        }
    }
    steps[num] = 1 + try_steps;
    return steps[num];
}
int main() {
    int N;
    std::cin>>N;
    for(int i = 0; i <= N; i++){
        steps[i] = -1;
    }
    std::cout<<min_steps(N)<<"\n";
}
