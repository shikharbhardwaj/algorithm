#include <iostream>
#include <vector>
int least_prime_factor[1000001];

void gen_least_primes() {
    for (auto &elem : least_prime_factor)
        elem = -1;
    least_prime_factor[0] = 1;
    least_prime_factor[1] = 1;
    least_prime_factor[2] = 2;
    for (int i = 4; i <= 1e6; i += 2)
        least_prime_factor[i] = 2;
    for (int i = 3; i <= 1e6; i += 2) {
        if (least_prime_factor[i] == -1)
            least_prime_factor[i] = i;
        for (long long j = i; j * i <= 1e6; j++) {
            if (j * i > 1e6) {
                std::cout << "wut" << std::endl;
                break;
            }
            if (least_prime_factor[j * i] == -1)
                least_prime_factor[j * i] = i;
        }
    }
}
int main() {
    int in;
    gen_least_primes();
    while (std::cin >> in)
        std::cout << least_prime_factor[in] << "\n";
}
