#include <iomanip>
#include <iostream>
#include <map>

int main() {
    std::cout << sizeof(unsigned char);
    std::ios_base::sync_with_stdio(false);
    int T;
    unsigned char ch;
    std::cin >> T;
    std::cin.ignore();
    while (T--) {
        std::map<unsigned char, double> price;
        double total = 0;
        int k, m;
        std::cin >> k;
        std::cin.ignore();
        for (int i = 0; i < k; i++) {
            double temp;
            std::cin >> ch;
            std::cin.ignore();
            std::cin >> temp;
            std::cin.ignore();
            temp /= 100;
            price[ch] = temp;
        }
        std::cin >> m;
        std::cin.ignore();
        std::string line;
        for (int i = 0; i < m; i++) {
            std::getline(std::cin, line);
            for (auto ch : line) {
                if (ch == '\n')
                    break;
                if (price.find(ch) != price.end())
                    total += price[ch];
            }
        }
        std::cout << std::fixed << std::setprecision(2) << total << "$\n";
    }
}
