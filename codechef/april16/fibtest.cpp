// Solution for : APRIL16/Fib
#include <iostream>
#include <bitset>
#include <vector>
// Looking for an empty mind
// Trying all possible outcomes
size_t N, N_cur, l, r;
std::bitset<4> bits;
std::bitset<4> one;
std::bitset<4> carry;
std::vector<int> vals({1, 2, 3, 4});
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
        std::cout << bits.to_string() << std::endl;
    }
    add_one();
    all_subsets();
}
int main() {
    N_cur = 3;
    all_subsets();
}
