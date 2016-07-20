// Implement a Fenwick tree (Binary indexed tree)
#include <iostream>
#include <vector>
std::vector<long long> BIT;
// The concept
//
// Every index can be represented as a sum of powers of 2
// The prefix sum upto the element can be determined by storing the sum
// across parents determined by the last set bit in the binary representation of
// the index.
long long query(size_t i) {
    long long ret = 0;
    i++;
    while (i > 0) {
        ret += BIT[i];
        i -= i & (-i);
    }
    return ret;
}
void update(size_t i, long long val) {
    // Update the value at index i to val
    // What should be the algorithm?
    //
    // Set the value at the index to val and update all parents
    i++;
    while (i < BIT.size()) {
        BIT[i] += val;
        // Go to parent
        i += i & (-i);
    }
}
void init(size_t n, const std::vector<long long> &ar) {
    BIT.assign(n + 1, 0);
    for (size_t i = 0; i < n; i++) {
        update(i, ar[i]);
    }
}
int main() {
    // Helps in answering the question -> what is the prefix sum upto element
    // at index i
}
