#include <cmath>
#include <iostream>
template <typename T> void repl(T a);
const float MAX = 1e9;
int main() {
    int H, U, D, F;
    while (true) {
        std::cin >> H >> U >> D >> F;
        if (H == 0) {
            break;
        }
        float a = -U * F / 100.f, b = 2 * (U - D) + U * F / 100.f,
              c = -2.f * (H - D);
        float det = b * b - 4 * a * c;
        // std::cout << det << "\n";
        // std::cout << a << " " << b << " " << c << "::";
        // std::cout << "D : " << D << " -> ";
        if (det > 0.01) {
            std::cout << "success on day ";
            float sol1 = (-b + sqrt(det)) / (2 * a);
            float sol2 = (-b - sqrt(det)) / (2 * a);
            sol1 = (sol1 > 0) ? sol1 : MAX;
            sol2 = (sol2 > 0) ? sol2 : MAX;
            std::cout << ceil(std::min(sol1, sol2)) << "\n";
        } else {
            std::cout << "failure on day ";
            std::cout << floor(-b / a) + 1 << "\n";
        }
    }
}
