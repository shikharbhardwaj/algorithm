#include <iostream>
using namespace std;
using LL = long long;
int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            if (y1 < y2) {
                std::cout << "up";
            } else {
                std::cout << "down";
            }
        } else if (y1 == y2) {
            if (x1 < x2) {
                std::cout << "right";
            } else {
                std::cout << "left";
            }
        } else {
            std::cout << "sad";
        }
        std::cout << std::endl;
    }
}
