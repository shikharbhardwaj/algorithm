#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <numeric>
#include <cassert>
#include <cmath>
using namespace std;
typedef unsigned int uint;
typedef unsigned long long LL;

#define FOR(k, a, b) for (uint k(a); k < (b); ++k)
#define REP(k, a) for (uint k = 0; k < (a); ++k)

const int MOD = 1e9 + 7;

LL invmod(LL a) {
    int p = MOD - 2;
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

LL calc(uint x, LL m, const vector<int> &v) {
    LL res = 0, tmp;
    --m;
    int u = m % MOD;
    LL d = 0;
    LL act = 1;
    REP(i, x) {
        tmp = act * v[x - 1 - i];
        tmp %= MOD;
        res += tmp;
        if (res >= MOD)
            res -= MOD;
        // Calculating the next coefficient
        if (d < m) {
            // If the value in the denominator does not
            // exceed the value of given power
            // What is d?
            //
            // The values progressing in the denominator
            act *= u + 1; // The mod value of pow + 1
            act %= MOD;
            act *= invmod(d + 1);
            act %= MOD;
            ++u;
            ++d;
        } else {
            // The last thing
            act *= u + 1;
            act %= MOD;
            act *= invmod(u + 1 - d);
            act %= MOD;
            ++u;
        }
    }
    return res;
}

int main() {
#ifdef HOME
    freopen("in.txt", "rb", stdin);
    freopen("out.txt", "wb", stdout);
#endif
    uint T, n, x;
    LL m, tmp, res;
    vector<int> v;
    scanf("%d", &T);
    assert(T > 0 && T < 11);
    while (T--) {
        scanf("%d %d %lld", &n, &x, &m);
        assert(0 < x && x <= n && n <= 1e5);
        assert(0 < m && m <= 1e18);
        v.resize(n);
        REP(i, n) {
            scanf("%lld", &tmp);
            assert(tmp > 0 && tmp <= 1e18);
            tmp %= MOD;
            v[i] = tmp;
        }
        res = calc(x, m, v);
        printf("%lld\n", res);
    }
    return 0;
}
