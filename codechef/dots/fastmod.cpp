#include <iostream>
int fast_mod_exp(int base, int exp, int mod) {
    int result = 1;
    if (mod == 1) {
        return 0;
    }
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
            result %= mod;
        }
        exp /= 2;
        base *= base;
        base %= mod;
        result %= mod;
    }
    return result;
}
int main() {}
