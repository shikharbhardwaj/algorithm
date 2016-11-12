// Linear won't work
// Now go for the juggernaut
#include <iostream>
#include <vector>
int main() {
    std::ios_base::sync_with_stdio(false);
    int S, B, L, R;
    while (true) {
        std::cin >> S >> B;
        std::vector<int> battlefront(S, 1);
        if (S == 0)
            break;
        for (int i = 0; i < B; i++) {
            std::cin >> L >> R;
            L--, R--;
            int j;
            for (j = L; j <= R; j++) {
                battlefront[j] = 0;
            }
            for (j = L - 1; j >= 0; j--) {
                if (battlefront[j]) {
                    std::cout << j + 1 << " ";
                    break;
                }
            }
            if (j == -1)
                std::cout << "* ";
            for (j = R + 1; j < S; j++) {
                if (battlefront[j]) {
                    std::cout << j + 1;
                    break;
                }
            }
            if (j == S)
                std::cout << "*";
            std::cout << "\n";
        }
        std::cout << "-\n";
    }
}
