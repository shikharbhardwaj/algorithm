#include <iostream>
#include <limits>
long long gcd(long long a, long long b) {
    long long rem = a % b;
    if (rem == 0) {
        return b;
    }
    return gcd(b, rem);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        long long A, B, C, D;
        std::cin >> A >> B >> C >> D;
        auto hcf = gcd(C, D);
        auto ans = std::abs(A - B) % hcf;
        if (ans > hcf / 2) {
            ans = hcf - ans;
        }
        std::cout << ans << "\n";
    }
}
