#include <iostream>
#include <random>

int T = 5;
int N_limit = 1e5;
int Q_limit = 1e5;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> Li(1, 1e9);
std::uniform_int_distribution<int> Ki(1, 1e9);

int main() {
    std::cout << T << std::endl;
    while (T--) {
        std::cout << N_limit << " " << Q_limit << std::endl;
        for (int i = 0; i < N_limit; ++i) {
            std::cout << Li(gen) << " ";
        }
        for (int i = 0; i < Q_limit; ++i) {
            std::cout << Ki(gen) << std::endl;
        }
    }
}
