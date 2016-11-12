#include <algorithm>
#include <iostream>
const int MOD = 1e9 + 7;
using LL = long long;
LL mod_pow(LL a, LL p) {
    LL res = 1;
    a %= MOD;
    while (p) {
        if (p & 1) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        p >>= 1;
    }
    return res;
}
int ans(int N) {
    if (N <= 2)
        return 0;
    return (mod_pow(2, N - 1) - 2) % MOD;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    int T, N;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        std::cout << ans(N) << "\n";
    }
}
