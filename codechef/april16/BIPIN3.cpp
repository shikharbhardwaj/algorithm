// Solution for : APRIL16/BIPIM3
#include <bits/stdc++.h>
const int max = 1e9 + 7;
long long pow_mod(long long a, long long b) {
    // Finding (a^b)%max
    //
    // Use Fermat's little theorem
    // (a^(max-2)) % max is the mod inverse
    long long x = 1, y = a;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x * y);
            if (x > max) {
                x %= max;
            }
        }
        y = y * y;
        if (y > max) {
            y %= max;
        }
        b /= 2;
    }
    return x;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    long long n, k;
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        if (n == 1) {
            std::cout << k % max << "\n";
        } else {
            std::cout << ((k % max) * (pow_mod(k - 1, n - 1) % max)) % max
                      << "\n";
        }
    }
}
