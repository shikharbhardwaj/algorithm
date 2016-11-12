#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
int max = 1e9 + 7;
int pow_mod(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    if (exp == 1) {
        return base % max;
    }
    if (exp % 2 == 1) {
        return ((pow_mod(base, exp / 2) % max) *
                (pow_mod(base, exp / 2) % max) * (base % max)) %
               max;
    }
    return ((pow_mod(base, exp / 2) % max) * (pow_mod(base, exp / 2) % max)) %
           max;
}
bool is_magical(const std::string &in) {
    int two_streak = 0;
    for (size_t i = 0; i < in.size(); i++) {
        if (in[i] == '1') {
            if (i == in.size() - 1 && two_streak == 2)
                return false;
            if (two_streak == 2)
                two_streak = 0;
            if (two_streak == 1)
                return false;
        }
        if (in[i] == '2') {
            two_streak++;
        }
    }
    if (two_streak != 1 && two_streak)
        return false;
    return true;
}
void generate(std::string &a, std::string &b, std::bitset<32> bits) {
    for (size_t i = 0; i < a.size(); i++) {
        if (bits.test(i)) {
            std::swap(a[i], b[i]);
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        std::string a, b;
        std::cin >> a >> b;
        assert(a.size() <= 10 && b.size() <= 10);
        long long cnt = 0;
        std::string temp1, temp2;
        for (long long i = 0; i < (1 << a.size()); i++) {
            temp1 = a, temp2 = b;
            generate(temp1, temp2, i);
            if (is_magical(temp1) && is_magical(temp2)) {
                cnt++;
            }
            // std::cout << std::endl << std::bitset<32>(i);
        }
        std::cout << cnt % max << "\n";
    }
}
