#include <iostream>
long long gcd(long long a, long long b) {
    auto rem = a % b;
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
        long long N, C;
        std::cin >> N >> C;
        if (N == 1) {
            std::cout << "Yes\n";
        } else {
            long long diff = C - (N * (N + 1) / 2);
            std::cout << diff;
            if (diff % N == diff % (N - 1) || (diff % N == 0)) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        }
    }
}
