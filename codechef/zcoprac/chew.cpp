#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(static_cast<std::ostream *>(nullptr));
}
size_t binary_search(std::vector<long long> &vec, size_t begin, size_t end,
                     long long key) {
    // Returns the first element that is greater than the key
    while (begin != end) {
        size_t mid = begin + (end - begin) / 2;
        if (vec[mid] <= key) {
            begin = mid + 1;
        } else {
            end = mid;
        }
    }
    return end;
}

int main() {
    fast_io();
    long long N, k, cnt = 0;
    std::unordered_map<long long, int> freq;
    std::cin >> N >> k;
    std::vector<long long> vals(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vals[i];
        if (freq.find(vals[i]) == freq.end()) {
            freq[vals[i]] = 1;
        } else {
            freq[vals[i]]++;
        }
    }
    std::sort(vals.begin(), vals.end());
    for (int i = 0; i < N;) {
        if (vals[i] >= k) {
            break;
        }
        long long nums = freq[vals[i]];
        long long j =
            (binary_search(vals, i + 1, vals.size(), k - vals[i] - 1)) - i -
            nums;
        if (2 * vals[i] < k) {
            cnt += nums * (nums - 1) / 2;
        }
        if (j > 0) {
            cnt += (j * nums);
        }
        i += nums;
    }
    std::cout << cnt << std::endl;
}
