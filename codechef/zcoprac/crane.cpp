#include <iostream>
#include <vector>
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(static_cast<std::ostream *>(nullptr));
}
int main() {
    int N, H, i, command;
    bool has_box = false;
    std::cin >> N >> H;
    std::vector<int> stacks(N);
    for (int i = 0; i < N; i++) {
        std::cin >> stacks[i];
    }
    i = 0;
    std::cin >> command;
    while (command != 0) {
        switch (command) {
        case 1:
            if (i != 0) {
                i--;
            }
            break;
        case 2:
            if (i != N - 1) {
                i++;
            }
            break;
        case 3:
            if (stacks[i] && !has_box) {
                stacks[i]--;
                has_box = true;
            }
            break;
        case 4:
            if (has_box && stacks[i] != H) {
                stacks[i]++;
                has_box = false;
            }
            break;
        }
        std::cin >> command;
    }
    for (auto elem : stacks) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
