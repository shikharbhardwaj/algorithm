#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    int result, ans;
    // Follow an optimal strategy
    std::cout << "1\n3 1 2 2\n3 3 4 4" << std::endl;
    std::cin >> result;
    switch (result) {
    case 0:
        ans = 5;
        break;
    case 1:
        ans = 1;
        break;
    case 2:
        ans = 2;
        break;
    case -1:
        ans = 3;
        break;
    case -2:
        ans = 4;
        break;
    }
    std::cout << "2\n" << ans << std::endl;
}
