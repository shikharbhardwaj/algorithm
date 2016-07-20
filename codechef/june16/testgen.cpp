#include <iostream>
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> N_dist(1e4 * 5, 1e5);
std::uniform_int_distribution<int> K_dist(1e4 * 5, 1e5);
std::uniform_int_distribution<int> A_dist(-1e6, 1e6);
int main() {
    int T = 50;
    std::cout << T << std::endl;
    while (T--) {
        int N = N_dist(gen);
        int K = K_dist(gen);
        std::cout << N << " " << K << "\n";
        while (N--) {
            std::cout << A_dist(gen) << " ";
        }
        std::cout << "\n";
    }
}
