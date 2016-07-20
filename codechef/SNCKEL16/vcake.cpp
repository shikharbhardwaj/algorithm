#include <iostream>
using namespace std;
int main() {
    // your code goes here
    long long int t, r, c, m, k, j;
    cin >> t;
    while (t--) {
        cin >> r >> c >> m >> k >> j;
        if (r * c < m + k + j || r * c > m + k + j) {
            cout << "No\n";
        } else {
            int num_div_r = 0;
            int num_div_c = 0;
            if (m % r == 0) {
                num_div_r++;
            }
            if (k % r == 0) {
                num_div_r++;
            }
            if (j % r == 0) {
                num_div_r++;
            }
            if (m % c == 0) {
                num_div_c++;
            }
            if (k % c == 0) {
                num_div_c++;
            }
            if (j % c == 0) {
                num_div_c++;
            }
            if (num_div_c >= 1 && num_div_r >= 1) {
                std::cout << "Yes\n";
            } else {
                std::cout << "No\n";
            }
        }
    }
    return 0;
}
