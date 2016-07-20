// Solution for : JUNE16/DEVARRAY
#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    int min, max, ai;
    std::cin >> min;
    N--;
    max = min;
    while (N--) {
        std::cin >> ai;
        if (ai < min) {
            min = ai;
        }
        if (ai > max) {
            max = ai;
        }
    }
    while (Q--) {
        int t;
        std::cin >> t;
        if (t > max || t < min) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
        }
    }
}
