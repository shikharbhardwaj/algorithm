// Solution for APR16/CHEFPATH
//
#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    unsigned long long N, M;
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> N >> M;
        if (N == 1 || M == 1) {
            // Corner case for vectors
            if (std::max(N, M) == 2) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        } else if (N % 2 == 0 || M % 2 == 0) {
            // A magical path exists only if the number of rows or columns is
            // even?
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
}
