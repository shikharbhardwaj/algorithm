#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int i, j;
        std::cin >> i >> j;
        if (i == j) {
            std::cout << "=\n";
        } else if (i < j) {
            std::cout << "<\n";
        } else {
            std::cout << ">\n";
        }
    }
}
