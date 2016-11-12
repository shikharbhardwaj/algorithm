#include <iostream>
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dist(1, 1e5);
std::bernoulli_distribution decide(0.5);
int main() {
    int T = 100;
    int N = 10000, M = 10000;
    std::uniform_int_distribution<int> pos(1, N);
    std::cout << T << "\n";
    while (T--) {
        std::cout << N << " " << M << "\n";
        for (int i = 0; i < N; i++) {
            std::cout << dist(gen) << " ";
        }
        std::cout << "\n";
        for (int i = 0; i < M; i++) {
            if (decide(gen)) {
                std::cout << "0 ";
            } else {
                std::cout << "1 ";
            }
            int left = pos(gen);
            int right = std::uniform_int_distribution<int>(left, N)(gen);
            std::cout << left << " " << right << "\n";
        }
    }
}
