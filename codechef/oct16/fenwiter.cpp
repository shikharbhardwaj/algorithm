#include <bitset>
#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    int T, N;
    std::cin >> T;
    while (T--) {
        std::string end, begin, rep;
        std::cin >> end >> rep >> begin;
        std::cin >> N;
        // Find the first zero
        int i;
        for (i = begin.size() - 1; i >= 0; i--) {
            if (begin[i] == '0') {
                break;
            }
        }
        long long steps = 0;
        if (begin[i] == '0') {
            for (int j = i - 1; j >= 0; j--) {
                if (begin[j] == '1')
                    steps++;
            }
            long long cnt = 0;
            for (auto elem : rep) {
                if (elem == '1') {
                    cnt++;
                }
            }
            steps += N * cnt;
            cnt = 0;
            for (auto elem : end) {
                if (elem == '1') {
                    cnt++;
                }
            }
            steps += cnt;
        } else {
            for (i = rep.size() - 1; i >= 0; i--) {
                if (rep[i] == '0') {
                    break;
                }
            }
            long long cnt = 0;
            if (rep[i] == '0') {
                for (int j = i - 1; j >= 0; j--) {
                    if (rep[j] == '1')
                        steps++;
                }
                for (auto elem : rep) {
                    if (elem == '1')
                        cnt++;
                }
                steps += (N - 1) * cnt;
                cnt = 0;
                for (auto elem : end) {
                    if (elem == '1')
                        cnt++;
                }
                steps += cnt;
            } else {
                for (i = end.size() - 1; i >= 0; i--) {
                    if (end[i] == '0')
                        break;
                }
                if (end[i] == '0') {
                    for (int j = i - 1; j >= 0; j--) {
                        if (end[j] == '1')
                            steps++;
                    }
                }
            }
        }
        std::cout << steps + 1 << "\n";
    }
}
