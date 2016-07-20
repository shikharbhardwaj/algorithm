#include <algorithm>
#include <iostream>
#include <vector>
long long get_distint_substrings(const std::string &in) {
    std::vector<std::string> suffixes(in.size());
    std::string suffix;
    int i = 0;
    for (auto elem : in) {
        suffix += std::string(1, elem);
        suffixes[i++] = suffix;
    }
    std::sort(suffixes.begin(), suffixes.end());
    long long LCP_sum = 0;
    for (size_t i = 1; i < suffixes.size(); i++) {
        for (size_t j = 0; j < suffixes[i - 1].size() && j < suffixes[i].size();
             j++) {
            if (suffixes[i - 1][j] == suffixes[i][j]) {
                LCP_sum++;
            } else {
                break;
            }
        }
        std::cout << suffixes[i] << LCP_sum << "\n";
    }
    return ((long long)in.size() * (long long)(in.size() + 1)) / 2 - LCP_sum;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::string in;
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> in;
        std::cout << get_distint_substrings(in) << "\n";
    }
}
