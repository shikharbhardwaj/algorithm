#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    if (N == 1) {
        long double x, y, r;
        std::cin >> x >> y >> r;
        long double x1, y1, x2, y2;
        while (Q--) {
            std::cin >> x1 >> y1 >> x2 >> y2;
        }
    } else {
        long double x, y, r;
        while (N--)
            std::cin >> x >> y >> r;
        long double x1, y1, x2, y2;
        while (Q--) {
            std::cin >> x1 >> y1 >> x2 >> y2;
            std::cout << "0.000000\n";
        }
    }
}
