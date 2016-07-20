
// Aim : Implement a Binary Indexed Tree
//
// Uses 1 based indexing
#include <bitset>
#include <iostream>
#include <vector>

using result_type = long long;
std::vector<result_type> BIT;

// The BIT is based on the concept of representation of integers in the binary
// number systems
//
// A number N can have at most ciel(lg(N)) bits set
//
// The representation of the number is characteristic to the bits set
//
// BIT[i] stores prefix sums upto the i-th power of 2
//
// For initializing ->
// Add the value of each index to each corresponding node of the BIT
//
// Now update the BIT at each index by traversing the elements of the BIT and
// calling update till the end of the BIT.
void update_BIT(size_t i, result_type val) {
    // Update the value at index i
    while (i < BIT.size()) {
        BIT[i] += val;
        i += (i & (-i));
    }
}
void update_range(size_t left, size_t right, result_type val) {
    update_BIT(left, val);
    update_BIT(right + 1, -val);
}
result_type query_BIT(int i) {
    // Return the prefix sum upto element i
    result_type ans = 0;
    while (i > 0) {
        ans += BIT[i];
        i -= (i & (-i));
    }
    return ans;
}
void init_BIT(const std::vector<result_type> &init) {
    BIT.assign(init.size(), 0);
    // Now update the BIT to store the prefix sums
    for (size_t i = 1; i < init.size(); i++) {
        update_BIT(i, init[i]);
    }
}
#define gc getchar_unlocked
void scanint(int &x) {
    int c = gc();
    x = 0;
    for (; (c < 48 || c > 57); c = gc())
        ;
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
}

int main() {
    int n, m, c;
    scanint(n);
    scanint(m);
    scanint(c);
    std::vector<result_type> init(n + 1, c);
    init[0] = 0;
    init_BIT(init);
    while (m--) {
        char choice;
        int left, right, k;
        scanf("%c", &choice);
        switch (choice) {
        case 'S':
            scanint(left);
            scanint(right);
            scanint(k);
            update_range(left, right, k);
            break;
        case 'Q':
            scanint(left);
            printf("%llu\n", query_BIT(left) + c);
            break;
        }
    }
}
