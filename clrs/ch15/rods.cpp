#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using vi = std::vector<int>;
// Program to solve the Rod cutting problem, demonstrating the principles
// of devising a dynamic programming.
int max_revenue(int length, vi &states, const vi &prices){
    if( length == 0 ){
        return 0;
    }
    if( states[length] == -1 ){
        int revenue = prices[length];
        for( int i = 1; i <= length - 1; i++ ){
            revenue = std::max(revenue, prices[i] + max_revenue(length - i,
                                                               states, prices));
        }
        states[length] = revenue;
    }
    return states[length];
}
int main(){
    int T, N;
    std::cin>>T;
    while( T-- ){
        std::cin>>N;
        vi states(N+1, -1);
        vi prices(N+1);
        std::generate(prices.begin(), prices.end(), []{
                    int ret;std::cin>>ret;return ret;
                });
        std::copy(prices.begin(), prices.end(), std::ostream_iterator<int>(std::cout, " "));
    }
}

