#include <iostream>
#include <random>
std::random_device rnd;
std::mt19937 gen(rnd());
std::uniform_int_distribution<int> c(0, 1e9);
std::bernoulli_distribution coin_distribution{0.85};
int main() {
    int n = 1e6, m = 25000;
    std::cout << n << " " << m << " " << c(gen) << std::endl;
    std::uniform_int_distribution<int> u(1, n - 1);
    std::uniform_int_distribution<int> p(1, n);
    while (m--) {
        if (coin_distribution(gen)) {
            int left = u(gen);
            std::uniform_int_distribution<int> v(left + 1, n);
            int right = v(gen);
            std::cout << "S " << left << " " << right << " " << c(gen) << "\n";
        } else {
            std::cout << "Q " << p(gen) << "\n";
        }
    }
}
