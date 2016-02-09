#include <iostream>
#include <unordered_map>
#include <vector>
typedef unsigned long long ull;
int main(){
    unsigned int N, length = 1;
    std::unordered_map<int, std::vector<int>> lengths;
    ull max, cur;
    int ans = 1;
    std::cin>>N;
    std::cin>>max;
    N--;
    while(N--){
        std::cin>>cur;
        if( cur > max ){
            max = cur;
            length = 1;
        }
        else if ( cur < max ){
            lengths[max].push_back(length);
            length = 0;
        }
        else if( cur == max ){
            length++;
        }
    }
    lengths[max].push_back(length);
    for( auto elem : lengths[max] ){
        if( ans < elem ){
            ans = elem;
        }
    }
    std::cout<<ans<<"\n";
    return 0;
}

