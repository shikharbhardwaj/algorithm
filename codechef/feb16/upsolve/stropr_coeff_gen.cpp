// Upsolve solution for : FEB16/stropr
#include <bits/stdc++.h>
const int max = 7 + 1e9;
long long mod_pow(long long a, long long b) {
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
long long mod_inv_fermat(long long a) { return mod_pow(a, max - 2); }
int coeff(int n, long long m) {
    long long ret = 1;
    long long cur;
    m %= max;
    for (int i = m; i > 0; i--) {
        cur = ((n + i - 1) % max * (mod_inv_fermat(i))) % max;
        ret *= cur;
        ret %= max;
    }
    return ret % max;
}
int main() {
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            std::cout << coeff(j, i) << "  : ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
