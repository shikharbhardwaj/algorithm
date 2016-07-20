
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
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, u;
        scanf("%d %d", &n, &u);
        init_BIT(std::vector<long long>(n + 1, 0));
        while (u--) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            update_range(l + 1, r + 1, k);
        }
        int q;
        scanf("%d", &q);
        while (q--) {
            int i;
            scanf("%d", &i);
            printf("%llu\n", query_BIT(i + 1));
        }
    }
}
