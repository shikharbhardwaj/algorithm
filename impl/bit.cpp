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
    std::vector<long long> freq = {0, 2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    init_BIT(freq);
    std::cout << "Sum of elements till 6th element " << query_BIT(6)
              << std::endl;
    update_BIT(4, 6);
    std::cout << "Updated sum " << query_BIT(6);
}
