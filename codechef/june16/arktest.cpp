#include <iostream>
#include <vector>

const int mod = 1e9 + 7;
using namespace std;
int count_fact(int n, int p) {
    // Counts the powers of p in n!
    int k = 0;
    while (n >= p) {
        k += n / p;
        n /= p;
    }
    return k;
}

long long mod_pow(long long a, long long b) {
    // Finding (a^b)%max
    //
    // Use Fermat's little theorem
    // (a^(max-2)) % max is the mod inverse
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
    return x;
}
long long mod_inv_fermat(long long a) { return mod_pow(a, mod - 2); }

long long factMOD(int n, int MOD) {
    long long res = 1;
    while (n > 0) {
        for (int i = 2, m = n % MOD; i <= m; i++)
            res = (res * i) % MOD;
        if ((n /= MOD) % 2 > 0)
            res = MOD - res;
    }
    return res;
}

long long C(int n, int r, int MOD) {
    if (count_fact(n, MOD) > count_fact(r, MOD) + count_fact(n - r, MOD))
        return 0;

    return (factMOD(n, MOD) * ((mod_inv_fermat(factMOD(r, MOD)) *
                                mod_inv_fermat(factMOD(n - r, MOD))) %
                               MOD)) %
           MOD;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int N, k, temp, num_zero = 0;
        std::cin >> N >> k;
        for (int i = 0; i < N; i++) {
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
        if (k >= N - 1) {
            ans = mod_pow(2, N - 1);
        } else if (k == N - 2) {
            ans = mod_pow(2, N - 1) - 1;
        } else {
            for (int i = k % 2; i <= k && i <= N; i += 2) {
                ans += C(N, i, mod);
                ans %= mod;
            }
        }
        std::cout << ans << "\n";
    }
}
