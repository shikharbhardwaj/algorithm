#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::vector<int> scores(N, 0);
        for (int i = 0; i < N; i++) {
            int cookies;
            std::cin >> cookies;
            int num_types = 0;
            int type_freq[6] = {0};
            for (int j = 0; j < cookies; j++) {
                int type;
                std::cin >> type;
                type--;
                if (type_freq[type] == 0)
                    num_types++;
                type_freq[type]++;
            }
            while (true) {
                int cookies = 0;
                if (num_types == 0)
                    break;
                int min = type_freq[0];
                cookies = type_freq[0];
                for (int i = 1; i < 6; i++) {
                    if (min == 0)
                        min = type_freq[i];
                    else if (min > type_freq[i] && type_freq[i])
                        min = type_freq[i];
                    cookies += type_freq[i];
                }
                if (num_types == 6)
                    scores[i] += min * 10;
                if (num_types == 5)
                    scores[i] += min * 7;
                if (num_types == 4)
                    scores[i] += min * 5;
                if (num_types < 4) {
                    scores[i] += cookies;
                    num_types = 0;
                    continue;
                }
                num_types = 0;
                for (int i = 0; i < 6; i++) {
                    if (type_freq[i]) {
                        type_freq[i] -= min;
                    }
                    if (type_freq[i])
                        num_types++;
                }
            }
        }
        bool tie = false;
        int max_score =
            std::max_element(scores.begin(), scores.end()) - scores.begin();
        for (int i = 0; i < N; i++) {
            if (i == max_score)
                continue;
            else if (scores[i] == scores[max_score]) {
                tie = true;
                break;
            }
        }
        if (!tie) {
            if (max_score == 0)
                std::cout << "chef\n";
            else
                std::cout << max_score + 1 << "\n";
        } else {
            std::cout << "tie\n";
        }
    }
}
