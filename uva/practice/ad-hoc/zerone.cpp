#include <iostream>
#include <vector>
int main() {
    // This is simple
    std::string in;
    int n, i, j;
    int cnt = 0;
    while (std::cin) {
        std::getline(std::cin, in);
        if (in.empty())
            break;
        std::vector<int> seq(in.size(), 1);
        auto cur = in[0];
        for (size_t i = 1; i < in.size(); i++) {
            if (in[i] == cur)
                seq[i] += seq[i - 1];
            else
                cur = in[i];
        }
        std::cin >> n;
        std::cin.ignore();
        cnt++;
        std::cout << "Case " << cnt << ":\n";
        for (int c = 0; c < n; c++) {
            std::cin >> i >> j;
            std::cin.ignore();
            int min = std::min(i, j);
            int max = std::max(i, j);
            i = min, j = max;
            if (seq[j] >= j - i + 1)
                std::cout << "Yes";
            else
                std::cout << "No";
            std::cout << "\n";
        }
    }
}
