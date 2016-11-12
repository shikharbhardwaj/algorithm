#include <iostream>
#include <vector>
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int N, temp, mark, i;
        std::cin >> N;
        std::vector<int> sums(N + 1, 0);
        std::vector<int> present(N + 1, -1);
        bool found = false, ans = false;
        for (i = 1; i <= N; i++) {
            std::cin >> temp;
            if (!found) {
                sums[i] = sums[i - 1] + temp;
                if (temp % N == 0) {
                    found = true;
                    ans = true;
                    std::cout << "1\n" << temp << "\n";
                } else if (present[sums[i] % N] != -1)
                    present[sums[i] % N] = i;
                else {
                    found = true;
                    mark = i;
                }
            }
        }
        if (!ans) {
            int first = present[sums[mark] % N];
            int second = mark;
            std::cout << second << first << "\n";
            for (int i = first; i <= second; i++) {
                std::cout << sums[i] - sums[i - 1] << " ";
            }
        }
    }
}
