#include <bits/stdc++.h>
int main() {
    int n;
    while (std::cin >> n) {
        std::vector<int> diffs(n, 0);
        int prev, cur;
        std::cin >> prev;
        for (int i = 1; i < n; i++) {
            std::cin >> cur;
            if (abs(cur - prev) < n) {
                diffs[abs(cur - prev)] = 1;
            }
            prev = cur;
        }
        bool jolly = true;
        for (int i = 1; i < n; i++) {
            if (diffs[i] == 0) {
                jolly = false;
                break;
            }
        }
        if (jolly) {
            std::cout << "Jolly\n";
        } else {
            std::cout << "Not jolly\n";
        }
    }
}
