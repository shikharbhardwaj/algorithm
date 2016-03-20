#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
const long long MAX = 1e9 + 7;
long long fact(long long n){
    long long ret = 1;
    for( long long i = 2; i <= n; i++ ){
        ret *= i;
    }
    return ret;
}
long long compute(const std::string &in){
    if( in.size() <= 1) {
        return 0;
    }
    std::array<long long, 26> freq;
    std::generate(freq.begin(), freq.end(), []{ return 0; });
    for( auto elem : in ){
        freq[elem-'a']++;
    }
    long long ans = fact(in.size()) * fact(in.size()-1);
    for( auto elem : freq ){
        ans /= (fact(elem));
    }
    return ans % MAX;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    long long T;
    std::string in;
    std::cin>>T;
    while(T--){
        std::cin>>in;
        std::cout<<compute(in)<<"\n";
    }
}
