#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
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
    std::sort(vals.begin(), vals.end(), std::greater<long long>());
    for (int i = 0; i < N;) {
        int pure_pairs = binary_search(vals, i + 1, vals.size(), vals[i] - k);
        pure_pairs++;
    }
    std::cout << cnt << std::endl;
}
