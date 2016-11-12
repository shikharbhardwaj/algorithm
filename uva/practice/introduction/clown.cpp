#include <bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; i++) {
        int N, min_speed, temp;
        std::cin >> N >> min_speed;
        for (int i = 1; i < N; i++) {
            std::cin >> temp;
            if (temp > min_speed) {
                min_speed = temp;
            }
        }
        std::cout << "Case " << i << ": " << min_speed << "\n";
    }
}
