#include <iostream>
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::pair<int, int> gen_pair(std::uniform_int_distribution<int> dist) {
    int l = dist(gen);
    int r = dist(gen);
    if (l == dist.max()) {
        // Try again
        return gen_pair(dist);
    }
    if (r <= l) {
        // Try again
        return gen_pair(dist);
    }
    return std::make_pair(l, r);
}
int main() {
    std::uniform_int_distribution<int> N_M(1, 1000);
    std::uniform_int_distribution<int> Y(1, 1e6);
    int N = N_M(gen);
    int M = N_M(gen);
    std::uniform_int_distribution<int>(1, N);
    std::cout << N << " " << M << "\n";
    while (N--) {
        std::cout << Y(gen) << " ";
    }
    std::cout << std::endl;
    while (M--) {
        auto test = gen_pair(N_M);
        std::cout << "Q " << test.first << " " << test.second << std::endl;
    }
}
