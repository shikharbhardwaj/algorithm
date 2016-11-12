#include "vector.hpp"
#include <vector>
template <typename T> void report(const T &vec) {
    std::cout << "Capacity : " << vec.capacity() << std::endl;
    std::cout << "Size : " << vec.size() << std::endl;
}
int main() {}
