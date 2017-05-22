#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

using ll = long long;
ll log2(ll in){
    return sizeof(in) * 8 - __builtin_clzll(in);
}

ll len(ll x){
    return ((ll)1 << log2(x)) - 1;
}

ll f(ll n, ll x) {
    if(n == 0 || x == 0){
        return 0;
    }
    if(x >= len(n)){
        return n;
    }
    if(x <= len(n / 2)){
        return f(n / 2, x);
    }
    return n / 2 + n % 2 + f(n / 2, x - len(n / 2) - 1);
}

int main(){
    std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");
    auto save_in = std::cin.rdbuf(fin.rdbuf());    // save and redirect
    auto save_out = std::cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
    ll x, l, r;
    std::cin >> x >> l >> r;
    std::cout << f(x, r) - f(x, l - 1) << std::endl;
#ifndef ONLINE_JUDGE
    std::cin.rdbuf(save_in);
    std::cout.rdbuf(save_out);
#endif
}
