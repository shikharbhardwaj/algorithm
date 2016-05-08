#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>
#include <vector>
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
    if( is_prime(n) == true){
        return 1;
    }
    int steps = 0;
    while( n > 0 ){
        std::vector<int> factors;
        int num = n;
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
        std::sort(factors.begin(), factors.end());
        int i = 1;
        while( num < factors[factors.size()-i] && num >= 0 ){
            i++;
        }
        num -= factors[factors.size() - i];
        n = num;
        steps++;
    }
    return steps;
}
int main() {
    int N;
    std::cin>>N;
    std::cout<<min_steps(N)<<"\n";
}
