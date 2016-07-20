// Submission for : SNCKQL16/MMSUM
#include <algorithm>
#include <iostream>
#include <vector>
// dp0 : Normal max subarray
// dp1 : Max subarray leaving one element
// Fail : 47 631 -748 -47
long long ar[100005];
long long dp0[100005];
long long dp1[100005];
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        for (int i = 0; i < N; i++) {
            std::cin >> ar[i];
        }
        dp0[0] = ar[0];
        dp1[0] = ar[0];
        for (int i = 1; i < N; i++) {
            dp0[i] = std::max(dp0[i - 1] + ar[i], ar[i]);
            dp1[i] = std::max(dp0[i - 1], dp1[i - 1] + ar[i]);
        }
        auto normal = *std::max_element(dp0, dp0 + N);
        auto skip = *std::max_element(dp1, dp1 + N);
        std::cout << std::max(normal, skip) << "\n";
    }
}
