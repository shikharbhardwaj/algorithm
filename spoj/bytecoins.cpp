#include <iostream>
#include <algorithm>
#include <array>
std::array<long long, 100001> optimal_revenues;
long long max_revenue(long long n){
    if ( n == 0 ){
        return 0;
    }
    if ( n <= 100000 ){
        if ( optimal_revenues[n] == -1 ){
            optimal_revenues[n] =  std::max(max_revenue(n/2) + max_revenue(n/3) + 
                                            max_revenue(n/4), n);
        }
        return optimal_revenues[n];
    }
    return std::max(max_revenue(n/2) + max_revenue(n/3) + max_revenue(n/4), n);
}
int main(){
    std::ios_base::sync_with_stdio(false); //Faster IO
    //Initialize the array with -1
    std::generate(optimal_revenues.begin(), optimal_revenues.end(), 
                    []{ return -1;});
    optimal_revenues[0] = 0;
    long long n;
    while ( std::cin>>n ){
        std::cout<<max_revenue(n)<<"\n";
    }
}

