#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    float H, U, D, F;
    while (true) {
        std::cin >> H >> U >> D >> F;
        if (H == 0) {
            break;
        }
        F /= 100.f;
        float cur_pos = 0.f;
        int day = 1;
        float def = U * F;
        while (true) {
            if (U > 0)
                cur_pos += U;
            if (cur_pos > H) {
                break;
            }
            cur_pos -= D;
            if (cur_pos < 0) {
                break;
            }
            U -= def;
            day++;
        }
        if (cur_pos > H) {
            std::cout << "success on day " << day << "\n";
        } else {
            std::cout << "failure on day " << day << "\n";
        }
    }
}
