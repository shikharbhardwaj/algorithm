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
            end = mid;
        } else {
            begin = mid + 1;
        }
    }
    return end;
}
int main() {
    std::vector<long long> in{4, 3, 2, 2};
    std::cout << binary_search(in, 0, 3, 2);
}
