#include <iostream>
#include <vector>
int res[1000][1000];
const int A = 1;
const int W = 4;
const int B = 5;
int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int N, M;
        std::cin >> N >> M;
        for (int i = 0; i < N; i++) {
            std::string row;
            std::cin >> row;
            for (int j = 0; j < M; j++) {
                switch (row[j]) {
                case 'W':
                    res[i][j] = W;
                    break;
                case 'B':
                    res[i][j] = B;
                    break;
                case 'A':
                    res[i][j] = A;
                    break;
                }
            }
        }
        bool valid = true;
        // Check if the base is not water
        for (int i = 0; i < M; i++) {
            if (res[N - 1][i] == W) {
                valid = false;
                break;
            }
        }
        // Check if boundaries are not water
        for (int i = 0; i < N; i++) {
            if (res[i][0] == W || res[i][M - 1] == W) {
                valid = false;
                break;
            }
        }
        // Now check for stability
        for (int i = 0; i < N && valid; i++) {
            for (int j = 0; j < M; j++) {
                if (i != 0) {
                    // Denser object above lighter one
                    if (res[i - 1][j] - res[i][j] > 0) {
                        valid = false;
                        break;
                    }
                }
                if (j != 0 && j != M - 1) {
                    int cur = res[i][j];
                    int left = res[i][j - 1];
                    int right = res[i][j + 1];
                    // Sideways flow possible
                    if (abs(cur - left) == 3 || abs(cur - right) == 3) {
                        valid = false;
                        break;
                    }
                }
            }
        }
        std::cout << ((valid) ? "yes\n" : "no\n");
    }
    return 0;
}
