#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
struct tree {
    int H, R;
    tree(int height, int rate) : H(height), R(rate) {}
};
int main() {
    std::ios_base::sync_with_stdio(false);
    int N;
    long long W, L;
    std::cin >> N >> W >> L;
    std::vector<tree> trees(N);
    for (int i = 0; i < N; i++) {
        std::cin >> trees[i].H >> trees[i].R;
    }
    std::sort(trees.begin(), trees.end(),
              [](tree const &first, tree const &second) -> bool {
                  return first.H < second.H;
              });
    // Create suffix array of Ri's, and Hi's
    std::vector<long long> r_sum(N);
    std::vector<long long> h_sum(N);
    r_sum[0] = trees[0].R;
    h_sum[0] = trees[0].H;
    for (int i = 1; i < N; i++) {
        r_sum[i] = r_sum[i - 1] + trees[i].R;
        h_sum[i] = h_sum[i - 1] + trees[i].H;
    }
    //
    // Done
    //
    while (true) {
        // For each month, calculate
    }
}
