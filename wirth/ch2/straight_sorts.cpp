#include <vector>
#include <chrono>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <random>
#include <cmath>
std::random_device rng;
std::mt19937 dist(rng());   //Generate some pseudo random numbers
std::uniform_int_distribution<int> generator(0, 1023);
template <typename iter,
         typename T = typename std::iterator_traits<iter>::value_type,
         class comp = std::less<T>>
void selection_sort(iter begin, iter end) {
    iter min = begin;
    for(; begin != end - 1; begin++) {
        iter cur = begin + 1;
        for(; cur != end; cur++) {
            if(*cur < *min) {
                min = cur;
            }
        }
        *begin = *min;
    }
}
template <typename iter,
         typename T = typename std::iterator_traits<iter>::value_type,
         class comp = std::less<T>>
void insertion_sort(iter begin, iter end) {
    iter cur = begin + 1;
    for(; cur != end; cur++) {
        iter needle = cur - 1;
        T value = *cur;
        while( *needle > value && needle != begin - 1 ) {
            *(needle+1) = *(needle);
            needle--;
        }
        *(needle+1) = value;
    }
}
template <typename iter,
         typename T = typename std::iterator_traits<iter>::value_type,
         class comp = std::less<T>>
void bubble_sort(iter begin, iter end) {
    iter limit = end;
    while(limit != begin) {
        iter cur = begin;
        for(; cur != limit - 1; cur++) {
            if(*(cur) > *(cur+1)) {
                std::swap(*(cur), *(cur+1));
            }
        }
        limit--;
    }
}
template <typename iter,
         typename T = typename std::iterator_traits<iter>::value_type,
         class comp = std::less<T>>
void shell_sub(iter begin, iter end, int jump) {
    iter cur = begin + jump;
    for(; cur < end; cur += jump) {
        iter needle = cur - jump;
        T value = *cur;
        while( *needle > value && needle > begin - 1 ) {
            *(needle+jump) = *(needle);
            needle -= jump;
        }
        *(needle + jump) = value;
    }

}
template <typename iter,
         typename T = typename std::iterator_traits<iter>::value_type,
         class comp = std::less<T>>
void shell_sort(iter begin, iter end) {
    //Using Knuth's divine advice
    int t = (log10(end - begin) / log10(3)) - 1;
    std::vector<int> seq(t);
    seq[0] = 1;
    for(int i = 1; i < t; i++) { //Generate the jump sequence
        seq[i] = 3 * seq[i-1] + 1;
    }
    while(t--) {
        shell_sub(begin, end, seq[t]);
    }
}
int main() {
    std::vector<int> lol;
    for(int i = 0; i < 1000; i++) {
        lol.push_back(generator(dist));
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    shell_sort(lol.begin(), lol.end());
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout<<"\nTime taken : "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
    assert(std::is_sorted(lol.begin(), lol.end()));
}

