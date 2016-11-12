// Aim : implement a working segment tree
#include <cmath>
#include <iostream>
#include <vector>
class segtree {
    using data_t = int;
    typedef struct interval {
        size_t left, right;
        data_t data;
        interval() = default;
        interval(size_t l, size_t r, data_t d) {
            left = l;
            right = r;
            data = d;
        }
    } interval;
    size_t n;
    std::vector<interval> tree;
    void combine(const interval &left, const interval &right, interval &result);
    void query(size_t cur, size_t left, size_t right, interval &ans) {
        if (tree[cur].left <= left && right <= tree[cur].right) {
            // This is relevant
            interval temp = ans;
            combine(tree[cur], temp, ans);
        }
    }

  public:
    segtree() = delete;
    segtree(std::initializer_list<data_t> ar) {
        // Initialize the segment tree from the array of elements
        // Number of elements in segtree = 2 ^ (floor(lg(n)) + 1);
        //
        size_t v = ar.size(), tree_size;
        if (!(v & (v - 1))) {
            // The number is a power of 2
            // Forget about 0
            tree_size = 2 * v;
        } else {
            tree_size = 1 << (int(log2(v)) + 1);
        }
        n = tree.size() / 2;
        tree.assign(tree_size, interval());
        // Copy the elements from the array to the leaves of the segtree
        size_t i = 0;
        for (auto it = ar.begin(); it != ar.end(); it++) {
            tree[i + n].left = tree[i + n].right = i + 1;
            tree[i + n].data = *it;
        }
        // Fill the rest of the elements with the null value
        while (i + n < tree_size) {
            tree[i + n].left = tree[i + n].right = i + 1;
            tree[i + n].data = data_t(); // Default construction
            i++;
        }
        // Now combine the info to the parents
        for (size_t i = n - 1; i >= 1; i--) {
            int left = i / 2;
            int right = left + 1;
            combine(tree[left], tree[right], tree[i]);
        }
    }
};
int main() {}
