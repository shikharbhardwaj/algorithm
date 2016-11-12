#include <iostream>
#include <vector>
// Implement Tarjan's algorithm
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int n, temp;
        std::cin >> n;
        std::vector<int> ids(n);
        for (int i = 0; i < n; i++) {
            std::cin >> temp;
            ids[i] = temp + i + 1;
            ids[i] %= n;
        }
        // Perform a dfs
    }
}
