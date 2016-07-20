// Solution for : JULY16/CHEFELEC
// We need rod cutting, with minimal revenue between two pairs of 1's
// and a single cut
#include <iostream>
#include <vector>
using ll = long long;
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::string state;
        std::vector<int> one_indices;
        std::vector<long long> prefix_sums(n, 0);
        std::cin >> state;
        for (int i = 0; i < n; i++) {
            if (state[i] == '1') {
                one_indices.push_back(i);
            }
        }
        for (int i = 0; i < n; i++) {
            std::cin >> prefix_sums[i];
        }
        auto start_index = one_indices[0];
        auto end_index = one_indices[one_indices.size() - 1];
        long long ans = prefix_sums[n - 1] - prefix_sums[end_index] +
                        prefix_sums[start_index] - prefix_sums[0];
        for (size_t i = 1; i < one_indices.size(); i++) {
            // The relevant range is one_indices[i-1] to one_indices[i]
            size_t left = one_indices[i - 1], right = one_indices[i];
#ifdef DEBUG
            std::cout << "Iter : [" << left << ", " << right << "]";
            std::cout << "\n";
#endif
            if (left + 1 == right) {
                continue;
            }
            std::vector<long long> suffix_sum(right - left + 1, 0);
            for (int i = suffix_sum.size() - 2; i >= 0; i--) {
                suffix_sum[i] = suffix_sum[i + 1] + prefix_sums[i + left + 1] -
                                prefix_sums[i + left];
            }
#ifdef DEBUG
            std::cout << "\n";
            for (auto elem : suffix_sum) {
                std::cout << elem << " : ";
            }
            std::cout << "\n";
            for (size_t i = left + 1; i <= right; i++) {
                std::cout << prefix_sums[i] - prefix_sums[left] << " : ";
            }
            std::cout << "\n";
#endif
            long long cur_cost = std::min(
                prefix_sums[right - 1] - prefix_sums[left], suffix_sum[1]);
            for (size_t i = left + 1; i < right; i++) {
                cur_cost =
                    std::min(cur_cost, prefix_sums[i] - prefix_sums[left] +
                                           suffix_sum[i - left + 1]);
            }
#ifdef DEBUG
            std::cout << "The cost : " << cur_cost << "\n";
#endif
            ans += cur_cost;
        }
        std::cout << ans << std::endl;
    }
}
