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
    std::vector<long long> vals(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vals[i];
    }
    std::sort(vals.begin(), vals.end());
    long long max_rev = vals[0] * N;
    for (int i = 1; i < N; i++) {
        if (vals[i] * (N - i) > max_rev) {
            max_rev = vals[i] * (N - i);
        }
    }
    std::cout << max_rev << std::endl;
}
