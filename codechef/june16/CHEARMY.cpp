#include <cmath>
#include <iostream>
unsigned long long pow5[26];
unsigned long long get_magical(unsigned long long k) {
    return 2000000000000000000 * ((k - 1) % pow5[19] / pow5[18]) +
           200000000000000000 * ((k - 1) % pow5[18] / pow5[17]) +
           20000000000000000 * ((k - 1) % pow5[17] / pow5[16]) +
           2000000000000000 * ((k - 1) % pow5[16] / pow5[15]) +
           200000000000000 * ((k - 1) % pow5[15] / pow5[14]) +
           20000000000000 * ((k - 1) % pow5[14] / pow5[13]) +
           2000000000000 * ((k - 1) % pow5[13] / pow5[12]) +
           200000000000 * ((k - 1) % pow5[12] / pow5[11]) +
           20000000000 * ((k - 1) % pow5[11] / pow5[10]) +
           2000000000 * ((k - 1) % pow5[10] / pow5[9]) +
           200000000 * ((k - 1) % pow5[9] / pow5[8]) +
           20000000 * ((k - 1) % pow5[8] / pow5[7]) +
           2000000 * ((k - 1) % pow5[7] / pow5[6]) +
           200000 * ((k - 1) % pow5[6] / pow5[5]) +
           20000 * ((k - 1) % pow5[5] / pow5[4]) +
           2000 * ((k - 1) % pow5[4] / pow5[3]) +
           200 * ((k - 1) % pow5[3] / pow5[2]) +
           20 * ((k - 1) % pow5[2] / pow5[1]) + 2 * ((k - 1) % pow5[1]);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    long long k;
    std::cin >> T;
    pow5[0] = 1;
    for (int i = 1; i < 26; i++) {
        pow5[i] = 5 * pow5[i - 1];
    }
    while (T--) {
        // Give the kth magical number
        std::cin >> k;
        std::cout << get_magical(k) << "\n";
    }
}
