#include <iostream>
int main() {
    const std::string WIN = "CONTEST_WON";
    const std::string TOP = "TOP_CONTRIBUTOR";
    const std::string BUG = "BUG_FOUND";
    const std::string HOST = "CONTEST_HOSTED";
    const std::string INDIAN = "INDIAN";
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while (T--) {
        std::string origin;
        int activities;
        int laddus = 0;
        std::cin >> activities >> origin;
        for (int i = 0; i < activities; i++) {
            std::string activity;
            std::cin >> activity;
            if (activity == WIN) {
                int rank;
                std::cin >> rank;
                if (rank < 20) {
                    laddus += 320 - rank;
                } else {
                    laddus += 300;
                }
            } else if (activity == TOP) {
                laddus += 300;
            } else if (activity == BUG) {
                int severity;
                std::cin >> severity;
                laddus += severity;
            } else {
                laddus += 50;
            }
        }
        if (origin == INDIAN) {
            std::cout << laddus / 200 << "\n";
        } else {
            std::cout << laddus / 400 << "\n";
        }
    }
}
