#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::string line;
    int cnt = 0;
    while (std::getline(std::cin, line)) {
        for (auto ch : line) {
            if (ch != '\"')
                std::cout << ch;
            else {
                cnt++;
                if (cnt % 2 == 1) {
                    std::cout << "``";
                } else {
                    std::cout << "''";
                }
            }
        }
        std::cout << "\n";
    }
}
