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
    ar = {0, 1, -4, 3, -4};
    std::cout << max_subarray(0, ar.size() - 1);
}
