#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N, temp;
        std::cin >> N;
        int num_unique = 0;
        int ones, zeroes, neg;
        ones = zeroes = neg = 0;
        if (N < 2) {
            std::cin >> temp;
            std::cout << "yes\n";
        } else {
            for (int i = 0; i < N; i++) {
                std::cin >> temp;
                if (temp == -1)
                    neg++;
                else if (temp == 0)
                    zeroes++;
                else if (temp == 1)
                    ones++;
                else
                    num_unique++;
            }
            if (num_unique >= 2)
                std::cout << "no\n";
            else {
                if (num_unique == 1 && neg == 0) {
                    std::cout << "yes\n";
                } else if (num_unique == 1 && neg != 0) {
                    std::cout << "no\n";
                } else if (num_unique == 0) {
                    if (neg == 0) {
                        std::cout << "yes\n";
                    } else if (ones == 0) {
                        if (neg == 1 && zeroes >= 1) {
                            std::cout << "yes\n";
                        } else {
                            std::cout << "no\n";
                        }
                    } else if (ones != 0 && neg != 0) {
                        std::cout << "yes\n";
                    } else {
                        std::cout << "no\n";
                    }
                }
            }
        }
    }
}
