#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    int N, temp;
    std::cin >> N;
    int cnt_even = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        if (temp % 2 == 0)
            cnt_even++;
    }
    if (cnt_even > N - cnt_even) {
        std::cout << "READY FOR BATTLE";
    } else {
        std::cout << "NOT READY";
    }
    std::cout << "\n";
}
