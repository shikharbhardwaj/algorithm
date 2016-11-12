#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    int k, n, m, x, y;
    while (std::cin >> k) {
        if (k == 0) {
            break;
        }
        std::cin >> n >> m;
        while (k--) {
            std::cin >> x >> y;
            x -= n;
            y -= m;
            if (x == 0 || y == 0) {
                std::cout << "divisa\n";
            } else if (x > 0) {
                if (y > 0)
                    std::cout << "NE\n";
                else
                    std::cout << "SE\n";
            } else {
                if (y > 0)
                    std::cout << "NO\n";
                else
                    std::cout << "SO\n";
            }
        }
    }
}
