// Solution for JULY16/EGRANDR
#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        bool full = false, fail = false;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int score;
            std::cin >> score;
            if (score == 2) {
                fail = true;
            } else if (score == 5) {
                full = true;
            }
            sum += score;
        }
        if (full && !fail && sum / (float)N >= 4) {
            std::cout << "Yes";
        } else {
            std::cout << "No";
        }
        std::cout << "\n";
    }
}
