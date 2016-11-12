#include <cmath>
#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    // const long double c = 299792458;
    std::cout.precision(6);
    while (T--) {
        long double s, v, t;
        std::cin >> s >> v;
        t = 2.f * s;
        t *= 1.f / (3.f * v);
        std::cout << std::scientific << t << "\n";
    }
}
