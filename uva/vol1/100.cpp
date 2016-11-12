#include <bits/stdc++.h>
using namespace std;
vector<int> lengths(10000001, -1);
int chainlength(int n) {
    if (n > 1000000) {
        if (n % 2 == 0) {
            return chainlength(n / 2) + 1;
        } else {
            return chainlength(3 * n + 1) + 1;
        }
    }
    if (n == 0) {
        return 0;
    }
    if (lengths[n] == -1) {
        if (n % 2 == 0) {
            lengths[n] = chainlength(n / 2) + 1;
        } else {
            lengths[n] = chainlength(3 * n + 1) + 1;
        }
    }
    return lengths[n];
}
int main() {
    lengths[1] = 1;
    ios_base::sync_with_stdio(false);
    int i, j;
    while (std::cin >> i >> j) {
        std::cout << i << " " << j << " ";
        vector<int> ij({i, j});
        sort(ij.begin(), ij.end());
        i = ij[0];
        j = ij[1];
        int max = -1;
        max = chainlength(i);
        i += 1;
        for (; i <= j; i++) {
            int length = chainlength(i);
            if (length > max) {
                max = length;
            }
        }
        std::cout << max << '\n';
    }
    // int n;
    // while (std::cin >> n) {
    // std::cout << chainlength(n) << std::endl;
    //}
}
