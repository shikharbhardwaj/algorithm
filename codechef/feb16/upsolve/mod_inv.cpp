#include <iostream>
#include <chrono>
const int max = 7 + 1e9;
int mod_inv(long long in) {
    // Simple brute force
    //
    // Problems :
    // Overflow on large numbers
    // Linear time complexity, non-poly in number of bits
    // We can do much better
    // Takes so much time that you may now stop using
    long long a = in % max;
    for (long long x = 1; x < max; x++) {
        if ((a * x) % max == 1) {
            return x;
        }
    }
    // This is the case of invalid input
    return -1;
}
std::pair<int, std::pair<int, int>> extended_euclid(int a, int b) {
    // A little more costly, but easier to code
    // Difference of about 1 microsecond
    if (a == 0) {
        return std::make_pair(b, std::make_pair(0, 1));
    }
    std::pair<int, std::pair<int, int>> p;
    p = extended_euclid(b % a, a);
    return make_pair(p.first,
                     std::make_pair(p.second.second - p.second.first * (b / a),
                                    p.second.first));
}
int mod_inv_enxtended(int a) {
    return (extended_euclid(a, max).second.first + max) % max;
}
long long mod_pow(long long a, long long b) {
    // Finding (a^b)%max
    //
    // Use Fermat's little theorem
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
    int ans;
    auto t1 = std::chrono::high_resolution_clock::now();
    ans = mod_inv_fermat(98);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "The modinv of 98 with 1e9 + 7 is " << ans;
    std::cout << std::endl;
    std::cout << "Time taken = "
              << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)
                     .count();
    std::cout << std::endl;
}
