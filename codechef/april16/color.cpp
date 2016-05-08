#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    int freq[3];
    std::string S;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::cin >> S;
        freq[0] = freq[1] = freq[2] = 0;
        for (auto elem : S) {
            if (elem == 'G') {
                freq[0]++;
            } else if (elem == 'R') {
                freq[1]++;
            } else if (elem == 'B') {
                freq[2]++;
            }
        }
        size_t i_max = std::max_element(freq, freq + 3) - freq;
        int ans = 0;
        for (size_t i = 0; i < 3; i++) {
            if (i == i_max) {
                continue;
            }
            ans += freq[i];
        }
        std::cout << ans << "\n";
    }
}
