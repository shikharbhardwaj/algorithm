#include <cassert>
#include <iostream>
#include <type_traits>
#include <vector>
template <typename Iter,
          typename Val = typename std::iterator_traits<Iter>::value_type>
Iter binary_search_exact(Iter begin, Iter end, const Val &key) {
    // Find the key in the range, any key in case of multiples
    assert(end - begin > 0);
    auto left = begin, right = end;
    while (left < right) {
        auto mid = left + (right - left) / 2;
        if (*mid == key) {
            return mid;
        } else if (*mid < key) {
            left = mid + 1;
        } else if (*mid > key) {
            right = mid;
        }
    }
    return end;
}
template <typename Iter,
          typename Val = typename std::iterator_traits<Iter>::value_type>
Iter binary_search_trip(Iter begin, Iter end, const Val &key) {
    // Find the first element which equals the key, or is greater than the key
    assert(end - begin > 0);
    auto left = begin, right = end;
    Iter mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (*mid < key) {
            left = mid + 1;
        } else if (*mid >= key) {
            if (mid == begin || *(mid - 1) < key) {
                break;
            } else {
                right = mid;
            }
        }
    }
    return mid;
}

int main() {
    std::vector<int> test_vec = {2, 2, 3, 5, 6, 7, 8, 9};
    int val;
    while (std::cin >> val) {
        std::cout << binary_search_trip(test_vec.begin(), test_vec.end(), val) -
                         test_vec.begin()
                  << "\n";
    }
}
