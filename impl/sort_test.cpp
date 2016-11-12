#include "qsort.hpp"
#include <iostream>
int main() {
    int ar[] = {5, 1, 3, 45, 6, 7};
    qsort4(ar, 0, sizeof(ar) / sizeof(int) - 1);
    for (auto elem : ar) {
        std::cout << elem << " : ";
    }
}
