#include <algorithm>
#include <iostream>
#include <vector>
template <typename T> T gcd(T a, T b) {
    T rem = a % b;
    if (rem == 0)
        return b;
    return gcd(b, rem);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::vector<long long> vals(N);
        for (auto &elem : vals) {
            std::cin >> elem;
        }
        std::sort(vals.begin(), vals.end());
        long long hcf = gcd(vals[0], vals[1]);
        long long min_pair = vals[0] * vals[1] / hcf;
        for (int i = 1; i < N; i++) {
            long long cur = vals[i];
            int j = i - 1;
            while (j >= 0) {
                if (cur * vals[j] / gcd(cur, vals[j]) < min_pair)
                    min_pair = cur * vals[j] / gcd(cur, vals[j]);
                j--;
            }
        }
        std::cout << min_pair << "\n";
    }
}
