#include <iostream>
void set_level(int level) {
#ifndef ONLINE_JUDGE
    while (level--) {
        std::cout << "\t";
    }
#endif
}
long long num_ways = 0;
void generate_partitions(int n, int k, int level) {
    // Enumerate all k sized partitions of n
    if (n == 0 || k == 0) {
        return;
    }
    set_level(level);
#ifndef ONLINE_JUDGE
    std::cout << n << " ";
#endif
    for (int i = 1; i < k; i++) {
#ifndef ONLINE_JUDGE
        std::cout << "0 ";
#endif
    }
#ifndef ONLINE_JUDGE
    std::cout << "\n";
#endif
    for (int i = 1; i < n; i++) {
        set_level(level);
#ifndef ONLINE_JUDGE
        std::cout << i << " ";
#endif
        if (k != 2) {
            generate_partitions(n - i, k - 1, level + 1);
        } else {
            std::cout << n - i << " ";
        }
#ifndef ONLINE_JUDGE
        std::cout << "\n";
#endif
    }
}
int main() {
    int n, k;
    std::cin >> n >> k;
    generate_partitions(n, k, 0);
    // The basic idea of the problem is to eliminate those configurations which
    // are duplicate.
}
