// Solution for :  APR16/Chefbllns
#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    long long colors[3], T, k;
    std::cin >> T;
    while (T--) {
        std::cin >> colors[0] >> colors[1] >> colors[2];
        std::cin >> k;
        size_t min_i = std::min_element(colors, colors + 3) - colors;
        if (colors[min_i] >= k) {
            // Yay!
            std::cout << 3 * k - 2;
        } else {
            bool too_bad = false;
            for (size_t i = 0; i < 3; i++) {
                if (i == min_i) {
                    continue;
                }
                if (colors[i] < k) {
                    too_bad = true;
                    std::cout << k + colors[i] + colors[min_i];
                    break;
                }
            }
            if (!too_bad) {
                std::cout << 2 * k - 1 + colors[min_i];
            }
        }
        std::cout << "\n";
    }
}
