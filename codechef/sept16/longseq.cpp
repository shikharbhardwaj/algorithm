#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    std::cin.ignore();
    while (T--) {
        std::string in;
        int zeros, ones;
        zeros = ones = 0;
        std::getline(std::cin, in);
        for (auto ch : in) {
            if (ch == '0')
                zeros++;
            else if (ch == '1')
                ones++;
        }
        if (zeros == 1 || ones == 1)
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }
}
