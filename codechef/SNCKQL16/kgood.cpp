#include <algorithm>
#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>
// Difference between any two frequencies must be <= k
std::vector<size_t> freq_table(26);
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        std::string word;
        size_t k, min = std::numeric_limits<int>::max();
        std::cin >> word;
        std::cin >> k;
        freq_table.assign(26, 0);
        for (auto elem : word) {
            freq_table[elem - 'a']++;
        }
        std::sort(freq_table.begin(), freq_table.end());
        for (int i = 0; i < 26; i++) {
            if (freq_table[i]) {
                min = i;
                break;
            }
        }
        // Find the compatible k val between the lowest and highest
        long long result = 0;
        size_t max = 25;
        while (max > min) {
            int min_cnt = 0, max_cnt = 1;
            if (freq_table[max] - freq_table[min] > k) {
                max_cnt = 0;
                for (int i = min; i < 26; i++) {
                    if (freq_table[i] == freq_table[min]) {
                        min_cnt++;
                    } else {
                        break;
                    }
                }
                for (int i = max; i >= 0; i--) {
                    if (freq_table[i] == freq_table[max]) {
                        max_cnt++;
                    } else {
                        break;
                    }
                }
                result += std::min(min_cnt, max_cnt);
            }
            max -= max_cnt;
            min += min_cnt;
        }
        std::cout << result << "\n";
    }
}
