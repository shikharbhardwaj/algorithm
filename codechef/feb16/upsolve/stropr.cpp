// Upsolve solution for : FEB16/stropr
#include <cstdio>
#include <vector>
#define REP(k, a) for (uint k = 0; k < (a); ++k)
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
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x, deno;
        long long N, M, temp, coeff, ans;
        scanf("%lld %d %lld", &N, &x, &M);
        std::vector<int> vals(N + 1);
        for (int i = 1; i <= N; i++) {
            scanf("%lld", &temp);
            temp %= max;
            vals[i] = temp;
        }
        ans = vals[x];
        coeff = 1;
        for (int i = x - 1; i >= 1; i--) {
            deno = x - i;
            temp = (M + deno - 1) % max;
            coeff = (coeff * temp) % max;
            coeff = (coeff * mod_inv_fermat(deno)) % max;
            ans = ans + (coeff * vals[i]);
            ans %= max;
        }
        printf("%lld\n", ans);
    }
}
