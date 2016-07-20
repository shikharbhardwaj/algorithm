#include <iostream>
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
int main() {
    int T = 10;
    std::cout << T << "\n";
    std::uniform_int_distribution<int> dist(-1e9, 1e9);
    std::uniform_int_distribution<int> num_dist(2, 1000);
    while (T--) {
        int N = num_dist(gen);
        std::cout << N << "\n";
        for (int i = 0; i < N; i++) {
            std::cout << dist(gen) << " ";
        }
        std::cout << "\n";
    }
}
