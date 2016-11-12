#include <iostream>
long long ar[100001];
long long br[100001];
// Keep track of the powers of 2 and 5 in the numbers
long long get_trailing_zeroes(long long n) {
    long long cnt = 0;
    while (n % 10 == 0 && n > 1) {
        n /= 10;
        cnt++;
    }
    return cnt;
}
void update_range_mul(long long l, long long r, long long X) {
    long long pow5 = 0, pow2 = 0;
    while (X % 2 == 0) {
        pow2++;
        X /= 2;
    }
    while (X % 5 == 0) {
        pow5++;
        X /= 5;
    }
    for (long long i = l; i <= r; i++) {
        ar[i] += pow2;
        br[i] += pow5;
    }
}
void update_range_repl(long long l, long long r, long long Y) {
    for (long long i = l; i <= r; i++) {
        long long val = Y * (i - l + 1);
        ar[i] = 0;
        br[i] = 0;
        while (val % 2 == 0) {
            ar[i]++;
            val /= 2;
        }
        while (val % 5 == 0) {
            br[i]++;
            val /= 5;
        }
    }
}
long long query_range(long long l, long long r) {
    long long ans2 = 0, ans5 = 0;
    for (long long i = l; i <= r; i++) {
        ans2 += ar[i];
        ans5 += br[i];
    }
    return std::min(ans2, ans5);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    long long T;
    std::cin >> T;
    while (T--) {
        long long N, M, temp;
        std::cin >> N >> M;
        for (long long i = 1; i <= N; i++) {
            std::cin >> temp;
            br[i] = ar[i] = 0;
            while (temp % 2 == 0) {
                ar[i]++;
                temp /= 2;
            }
            while (temp % 5 == 0) {
                br[i]++;
                temp /= 5;
            }
        }
        long long type, L, R, X, Y;
        long long sum = 0;
        for (long long i = 0; i < M; i++) {
            std::cin >> type;
            switch (type) {
            case 1:
                std::cin >> L >> R >> X;
                update_range_mul(L, R, X);
                break;
            case 2:
                std::cin >> L >> R >> Y;
                update_range_repl(L, R, Y);
                break;
            default:
                std::cin >> L >> R;
                sum += query_range(L, R);
                // std::cout << query_range(L, R) << "\n";
            }
        }
        std::cout << sum << "\n";
    }
}
