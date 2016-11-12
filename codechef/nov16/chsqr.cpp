#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int K;
        std::cin >> K;
        std::vector<int> num_vec(K);
        int n = 1;
        std::generate(num_vec.begin(), num_vec.end(), [&n] { return n++; });
        std::vector<std::vector<int>> grid(K);
        int rot_val = K / 2;
        std::generate(grid.begin(), grid.end(), [&rot_val, &num_vec] {
            auto cpy = num_vec;
            rot_val++;
            rot_val %= num_vec.size();
            std::rotate(cpy.begin(), cpy.begin() + rot_val, cpy.end());
            return cpy;
        });
        for (auto row : grid) {
            for (auto elem : row) {
                std::cout << elem << " ";
            }
            std::cout << "\n";
        }
    }
}
