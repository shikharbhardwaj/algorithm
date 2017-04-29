#include <iostream>
#include <vector>
#include <algorithm>
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(static_cast<std::ostream *>(nullptr));
}
int main() {
    fast_io();
    int N;
    std::cin >> N;
    std::vector<long long> strengths(N);
    std::vector<long long> prefix_sum(N);
    for (int i = 0; i < N; i++) {
        std::cin >> strengths[i];
    }
    std::sort(strengths.begin(), strengths.end(), std::greater<long long>());
    long long ans = 0;
    prefix_sum[0] = strengths[0];
    for (int i = 1; i < N; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + strengths[i];
    }
    for (int i = 0; i < N; i++) {
        ans += (long long)(N - i - 1) * strengths[i];
        ans -= (prefix_sum[N - 1] - prefix_sum[i]);
    }
    std::cout << ans << std::endl;
}
