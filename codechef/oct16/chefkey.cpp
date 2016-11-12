#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int n, m, c;
        std::cin >> n >> m >> c;
        int ways = 0;
        int limit = int(sqrt(c)) + 1;
        for (int i = 1; i < limit; i++) {
            if (c % i == 0) {
                int l = c / i, r = i;
                if (l != r) {
                    if (l <= m && r <= n) {
                        ways++;
                    }
                    if (r <= m && l <= n) {
                        ways++;
                    }
                } else {
                    if (l <= m && r <= n) {
                        ways++;
                    } else if (l <= n && r <= m) {
                        ways++;
                    }
                }
            }
            std::cout << ways << "\n";
        }
    }
}
