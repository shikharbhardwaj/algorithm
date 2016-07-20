#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
// Find out the max sum subarray of the given list of integers
std::vector<int> ar;
int max_crossing_subarray_crossing(int lo, int hi, int mid) {
    int left_sum, right_sum;
    left_sum = right_sum = std::numeric_limits<int>::min();
    int sum = 0;
    for (int i = mid; i >= lo; i--) {
        sum += ar[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= hi; i++) {
        sum += ar[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }
    return left_sum + right_sum;
}
int max_subarray(int lo, int hi) {
    if (lo == hi) {
        return ar[lo];
    }
    int mid = lo + (hi - lo) / 2;
    return std::max(max_subarray(lo, mid),
                    std::max(max_crossing_subarray_crossing(lo, hi, mid),
                             max_subarray(mid + 1, hi)));
}
int main() {
    int T, N;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        ar.assign(N, 0);
        for (int i = 0; i < N; i++) {
            std::cin >> ar[i];
        }
        std::vector<int> results;
        results.push_back(max_subarray(0, ar.size() - 1));
        auto aux = ar;
        for (int i = 0; i < N; i++) {
            ar = aux;
            ar.erase(ar.begin() + i);
            results.push_back(max_subarray(0, ar.size() - 1));
        }
        std::cout << *std::max_element(results.begin(), results.end())
                  << std::endl;
    }
}
