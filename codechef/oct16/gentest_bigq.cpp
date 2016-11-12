#include <iostream>
#include <random>
const int N = 10000, M = 90000;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> A(1e9, 1e9);
std::uniform_int_distribution<int> XY(1, N);
std::uniform_int_distribution<int> type(1, 3);
int main() {
    int T = 5;
    std::cout << T << "\n";
    while (T--) {
        std::cout << N << " " << M << "\n";
        for (int i = 0; i < N; ++i) {
            std::cout << A(gen) << " ";
        }
        std::cout << "\n";
        for (int i = 0; i < M; i++) {
            int t = type(gen);
            int l = XY(gen);
            std::uniform_int_distribution<int> right(l, N);
            int r = right(gen);
            if (t == 1) {
                std::cout << "1 " << l << " " << r << " " << A(gen) << "\n";
            } else if (t == 2) {
                std::cout << "2 " << l << " " << r << " " << A(gen) << "\n";
            } else {
                std::cout << "3 " << l << " " << r << "\n";
            }
        }
    }
}
