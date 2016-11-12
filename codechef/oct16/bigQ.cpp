#include <iostream>

int get_trailing_zeros(int n) {
    int trailing_zeros = 0;
    int tmp;
    while ((tmp = n / 5) >= 1) {
        trailing_zeros += tmp;
        n = tmp;
    }
    return trailing_zeros;
}
int main() { std::cout << get_trailing_zeros(25); }
