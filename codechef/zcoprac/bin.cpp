#include <iostream>
#include <vector>
size_t binary_search(std::vector<int> &vec, size_t begin, size_t end, int key) {
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
    std::vector<int> test{0, 1, 1, 3, 5, 5, 10};
    std::cout << binary_search(test, 0, test.size(), 3);
}
