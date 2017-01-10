#include <iostream>
bool is_possible(long long C, long long D, long long L) {
    if (L % 4 || L > (C + D) * 4) {
        return false;
    }
    // The max number of legs needed are
    // C + D * 4
    // The minimum is
    // D * 4 if 2 * D >= C
    // ow if all the cats ride, then
    // D * 4 + C - 2 * D
    if (L >= D * 4 && 2 * D >= C) {
        return true;
    }
    if (L >= D * 4 + (C - 2 * D) * 4 && 2 * D < C) {
        return true;
    }
    return false;
}
int main() {
    int T, C, D, L;
    std::cin >> T;
    while (T--) {
        std::cin >> C >> D >> L;
        std::cout << ((is_possible(C, D, L)) ? "yes\n" : "no\n");
    }
}
