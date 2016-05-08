#include <iostream>
// Efficientlty compute the nth fibonacci number
const int max = 1e9 + 7;
long long mat[2][2] = {{1, 1}, {1, 0}};
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
int main() { std::cout << '\n' << fib_n(7); }
