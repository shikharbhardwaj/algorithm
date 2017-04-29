// Solution for : APRIL16/Fib
#include <iostream>
#include <bitset>
#include <vector>
// Trying all possible outcomes
size_t N, N_cur, l, r;
std::bitset<1001> bits;
std::bitset<1001> one;
std::bitset<1001> carry;
std::vector<int> vals({1, 2, 3, 4});
// Efficientlty compute the nth fibonacci number
// Can also be used to compute the Lucas numbers
const int max = 1e9 + 7;
long long ans = 0;
long long mat[2][2] = {{1, 1}, {1, 0}}; // The initial matrix
void multiply(long long first[2][2], long long second[2][2]) {
    // Multiply the two matrices and store the result in the first matrix
    long long a, b, c, d;
    a = (first[0][0] * second[0][0] % max + first[0][1] * second[1][0] % max);
    b = (first[0][0] * second[0][1] % max + first[0][1] * second[1][1] % max);
    c = (first[1][0] * second[0][0] % max + first[1][1] * second[1][0] % max);
    d = (first[1][0] * second[0][1] % max + first[1][1] * second[1][1] % max);
    first[0][0] = a % max;
    first[0][1] = b % max;
    first[1][0] = c % max;
    first[1][1] = d % max;
}
void bin_pow(long long in[2][2], long long n) {
    if (n == 0 || n == 1) {
        return;
    }
    long long mult[2][2] = {{1, 1}, {1, 0}};
    bin_pow(in, n / 2);
    multiply(in, in);
    if (n % 2 == 1) {
        multiply(in, mult);
    }
}
int fib_n(long long n) {
    // The nth fibonacci number in O(lg n)
    long long mat[2][2] = {{1, 1}, {1, 0}};
    if (n == 0) {
        return 0;
    }
    bin_pow(mat, n - 1);
    return mat[0][0];
}
void add_one() {
    while ((bits & one).any()) {
        bits = bits ^ one;
        one <<= 1;
    }
    bits = bits ^ one;
    one.reset();
    one.set(0);
}
void all_subsets() {
    if (bits.any()) {
        if (bits.test(N_cur)) {
            return;
        }
        long long sum = 0;
        for (size_t i = l - 1; i < r; i++) {
            if (bits[i - l + 1]) {
                sum += vals[i];
            }
        }
        ans += fib_n(sum);
        if (ans > max) {
            ans -= max;
        }
    }
    add_one();
    all_subsets();
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(static_cast<std::ostream *>(nullptr)); // Why?
    int M;
    std::cin >> N >> M;
    vals = std::vector<int>(N);
    for (size_t i = 0; i < N; i++) {
        std::cin >> vals[i];
    }
    while (M--) {
        char ch;
        std::cin >> ch >> l >> r;
        // We are only aiming for the first subtest
        ans = 0;
        N_cur = (r - l + 1);
        bits.reset();
        one.reset();
        one.set(0);
        all_subsets();
        std::cout << ans % max << "\n";
    }
}
