#include <iostream>
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<long long> dist(1, 1e14);
int main() {
    int T = 10;
    std::cout << T << "\n";
    while (T--) {
        std::cout << dist(gen) << " " << dist(gen) << " " << dist(gen) << " "
                  << dist(gen) << "\n";
    }
}
