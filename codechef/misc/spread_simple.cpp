#include <iostream>
#include <vector>
int main() {
    int n, m, c;
    std::cin >> n >> m >> c;
    std::vector<long long> elems(n, c);
    while (m--) {
        char choice;
        int left, right, k;
        std::cin >> choice;
        switch (choice) {
        case 'S':
            std::cin >> left >> right >> k;
            left--, right--;
            for (int i = left; i <= right; i++) {
                elems[i] += k;
            }
            break;
        case 'Q':
            std::cin >> left;
            std::cout << elems[left - 1] << "\n";
            break;
        }
    }
}
