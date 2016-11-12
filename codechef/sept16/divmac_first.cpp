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
        for (int j = 2; j * i <= 1e6; j++) {
            if (least_prime_factor[j * i] == -1)
                least_prime_factor[j * i] = i;
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    int T, N, M;
    std::cin >> T;
    gen_least_primes();
    while (T--) {
        int type, L, R;
        std::cin >> N >> M;
        std::vector<int> nums(N + 1);
        for (int i = 1; i <= N; i++) {
            std::cin >> nums[i];
        }
        for (int i = 0; i < M; i++) {
            std::cin >> type >> L >> R;
            if (type == 0)
                for (int i = L; i <= R; i++)
                    nums[i] /= least_prime_factor[nums[i]];
            else {
                int result = 1;
                for (int i = L; i <= R; i++)
                    result = std::max(result, least_prime_factor[nums[i]]);
                std::cout << result << " ";
            }
        }
        std::cout << "\n";
    }
}
