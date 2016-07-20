#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    int N;
    std::cin >> T;
    while (T--) {
        std::cin >> N;
        if (N % 6 == 0) {
            std::cout << "Misha\n";
        } else {
            std::cout << "Chef\n";
        }
    }
}
