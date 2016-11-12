#include <cctype>
#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        long long sum = 0;
        std::string in;
        std::cin >> in;
        for (auto ch : in) {
            if (isdigit(ch)) {
                sum += ch - '0';
            }
        }
        std::cout << sum << "\n";
    }
}
