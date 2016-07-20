#include <cassert>
#include <iostream>
#include <type_traits>
#include <vector>
template <typename RandomAccessIterator,
          typename Vtype =
              typename std::iterator_traits<RandomAccessIterator>::value_type,
          typename Comparator = std::less<Vtype>>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end,
                    Comparator order = Comparator()) {
    assert(end - begin > 0);
    for (auto it = begin + 1; it != end; it++) {
        auto jt = it - 1;
        auto cur_val = *it;
        while (jt != begin - 1 && order(*jt, cur_val)) {
            *(jt + 1) = *jt;
            jt--;
        }
        *(jt + 1) = cur_val;
    }
}
template <typename RandomAccessIterator,
          typename Vtype =
              typename std::iterator_traits<RandomAccessIterator>::value_type,
          typename Comparator = std::less<Vtype>>
void selection_sort(RandomAccessIterator begin, RandomAccessIterator end,
                    Comparator order = Comparator()) {
    assert(end - begin > 0);
    for (auto it = begin; it != end - 1; it++) {
        auto jt = it + 1;
        auto min = jt;
        jt++;
        while (jt != end) {
            if (!order(*min, *jt)) {
                min = jt;
            }
            jt++;
        }
        std::iter_swap(it, min);
    }
}

int main() {
    std::vector<int> test_vec = {7, 3, 4, 1, 1, 100, 1};
    selection_sort(test_vec.begin(), test_vec.end());
    for (auto elem : test_vec) {
        std::cout << elem << ", ";
    }
}
