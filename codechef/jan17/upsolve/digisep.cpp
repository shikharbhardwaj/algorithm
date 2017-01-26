#include <cassert>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif
#include <iostream>
#include <vector>
using ull = unsigned long long;
ull gcd(ull a, ull b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ull gcd_ar(std::vector<ull> &ar) {
    ull g = 0;
    for (size_t i = 0; i < ar.size(); i++) {
        g = gcd(g, ar[i]);
    }
    return g;
}
std::string digits;

int main() {
    int T, N, M, X, Y;
#ifndef ONLINE_JUDGE
    if (std::freopen("sep.in", "r", stdin) == 0) {
        return 1;
    }
#endif
    std::cin >> T;
    while (T--) {
        std::cin >> N >> digits >> M >> X >> Y;
        // Brute force FTW
        assert(N <= 20);
        std::vector<ull> ans;
        ull max = 0;
        for (int i = (1 << (Y)) - 1; i <= (1 << X); i++) {
            int cur = 0;
            for (int j = 0; j < N; j++) {
                cur *= 10;
                cur += digits[j] - '0';
                if (i & (1 << j)) {
                    ans.push_back(cur);
                    cur = 0;
                }
            }
            ans.push_back(cur);
            auto cur_gcd = gcd_ar(ans);
            if (cur_gcd > max) {
                max = cur_gcd;
            }
            ans.clear();
        }
        std::cout << max << '\n';
    }
}
