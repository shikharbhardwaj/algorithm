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
LL invmod(LL a) { return mod_pow(a, MOD - 2); }
int main() {}
