#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int n, m;
        std::cin >> n >> m;
        if (n % 2 == 0 || m % 2 == 0) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
}
