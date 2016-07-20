#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int N, cur, cnt = 1, temp;
        std::cin >> N;
        bool found = false;
        std::cin >> cur;
        N--;
        while (N--) {
            std::cin >> temp;
            if (!found) {
                if (temp == cur) {
                    cnt++;
                    if (cnt == 3) {
                        found = true;
                    }
                } else {
                    cur = temp;
                    cnt = 1;
                }
            }
        }
        if (found) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
}
