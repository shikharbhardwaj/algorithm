// The possibilities
// The changes can take place from within the array
#include <iostream>
#include <vector>
int main() {
    int T;
    std::ios_base::sync_with_stdio(false);
    std::cin >> T;
    while (T--) {
        std::string a, b;
        bool has_zero = false, has_one = false;
        int ans = -1;
        int num_zero = 0, num_one = 0;
        std::cin >> a >> b;
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i] == '1') {
                has_one = true;
            } else {
                has_zero = true;
            }
            if (a[i] != b[i]) {
                if (a[i] == '1') {
                    has_one = true;
                    num_one++;
                } else {
                    has_zero = true;
                    num_zero++;
                }
            }
        }
        if (num_one == num_zero && has_one && has_zero) {
            ans = num_one;
        } else {
            if (num_one > num_zero && has_zero) {
                ans = num_one;
            } else if (num_one < num_zero && has_one) {
                ans = num_zero;
            }
        }
        if (ans != -1) {
            std::cout << "Lucky Chef\n" << ans << "\n";
        } else {
            std::cout << "Unlucky Chef\n";
        }
    }
}
