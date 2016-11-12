#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::vector<int> stack;
    int N, type, temp;
    std::cin >> N;
    while (N--) {
        std::cin >> type;
        switch (type) {
        case 1:
            std::cin >> temp;
            stack.push_back(temp);
            break;
        case 2:
            stack.pop_back();
            break;
        case 3:
            std::cout << *std::max_element(stack.begin(), stack.end()) << "\n";
            break;
        }
    }
}
