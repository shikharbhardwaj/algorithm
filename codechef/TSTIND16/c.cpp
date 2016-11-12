#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MOD = 1e9 + 7;
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
int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
    }
}
