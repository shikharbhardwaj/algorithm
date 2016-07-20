#include <iostream>

const long long mod = 1e9 + 7;

long long mod_pow(long long a, long long b) {
    long long x = 1, y = a;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x * y);
            if (x > mod) {
                x %= mod;
            }
        }
        y = y * y;
        if (y > mod) {
            y %= mod;
        }
        b /= 2;
    }
    return x % mod;
}
long long mod_inv_fermat(long long a) { return mod_pow(a, mod - 2); }

int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        long long N, k, num_zero = 0;
        std::cin >> N >> k;
        for (int i = 0; i < N; i++) {
            int temp;
            std::cin >> temp;
            if (temp == 0) {
                num_zero++;
            }
        }
        //
        // Calculate the number of different arrays
        // The answer depends on whether k is odd or even
        //
        // If k is even : The answer is the sum of all even binomial
        // coefficients till 0 from k
        //
        // If k is odd  : The answer is the sum of all odd  binomial
        // coefficients till 1 from k
        //
        // In case of zeroes, a correction needs to be made
        //
        if (num_zero != 0) {
            N -= num_zero;
            N++;
        }
        long long ans = 0;
        // We need to recalculate stuff
        long long prev;
        if (k % 2) {
            prev = N;
        } else {
            prev = 1;
        }
        ans += prev;
        for (long long i = k % 2; i < k && i < N; i += 2) {
            long long numerator = ((N - i - 1) % mod) * ((N - i) % mod);
            numerator %= mod;
            long long deno = mod_inv_fermat((i + 2) % mod * (i + 1) % mod);
            long long comb = (numerator * deno) % mod;
            comb *= prev;
            comb %= mod;
            prev = comb;
            ans += comb;
            ans %= mod;
        }
        std::cout << ans << "\n";
    }
}
