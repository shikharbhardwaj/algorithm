// Use segtree with vectors approach
// The root node can have a vector of the next prime factors
// During updates, we just upadate the max_prime from the leaves, O(lg n)
// During queries, we just fetch the max from the roots
#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>
int least_prime_factor[1000001];
void gen_least_primes() {
    for (auto &elem : least_prime_factor)
        elem = -1;
    least_prime_factor[0] = 1;
    least_prime_factor[1] = 1;
    least_prime_factor[2] = 2;
    for (int i = 4; i <= 1e6; i += 2)
        least_prime_factor[i] = 2;
    for (int i = 3; i <= 1e6; i += 2) {
        if (least_prime_factor[i] == -1)
            least_prime_factor[i] = i;
        for (int j = 2; j * i <= 1e6; j++) {
            if (least_prime_factor[j * i] == -1)
                least_prime_factor[j * i] = i;
        }
    }
}
// Begin segtree
//
// Uses 1 based indexing
typedef struct interval {
    int left, right;
    int prime = 1;
    bool update = false;
    std::vector<int> *prime_data = nullptr;
} interval;
int get_tree_size(int n) {
    // Assuming n != 0
    if (!(n & (n - 1))) {
        return 2 * n;
    } else {
        return 1 << int(round(log2(n)) + 1);
    }
}
interval segtree[2097152];
int size, N;
int a[1000001];

void fill_primes(int n, std::vector<int> &primes) {
    while (n != 1) {
        primes.push_back(least_prime_factor[n]);
        n /= least_prime_factor[n];
    }
    primes.push_back(1);
    std::reverse(primes.begin(), primes.end());
}
void init_segtree(int n) {
    size = get_tree_size(n);
    N = size / 2;
    for (int i = N; i < N + n; i++) {
        // These are the leaf nodes
        segtree[i].right = segtree[i].left = i - N + 1;
        segtree[i].prime_data = new std::vector<int>;
        fill_primes(a[i - N], *segtree[i].prime_data);
        segtree[i].prime = segtree[i].prime_data->back();
    }
    for (int i = N + n; i < size; i++) {
        segtree[i].right = segtree[i].left = i - N + 1;
    }
    for (int i = N - 1; i > 0; i--) {
        auto &left = segtree[2 * i];
        auto &right = segtree[2 * i + 1];
        segtree[i].left = left.left;
        segtree[i].right = right.right;
        segtree[i].prime = std::max(left.prime, right.prime);
    }
}
void update_segtree(int id, int left, int right) {
    auto &cur = segtree[id];
    if (cur.update) {
        if (cur.left != cur.right) {
            if (2 * id < size) {
                segtree[2 * id].update = true;
            }
            if (2 * id + 1 < size) {
                segtree[2 * id + 1].update = true;
            }
        } else {
            // This is a root node that needs an update
        }
    }
    if (cur.left > right || cur.right < left) {
        // This is disjoint
        return;
    }
    if (left <= cur.left && right >= cur.right) {
        if (cur.left != cur.right) {
            if (2 * id < size) {
                segtree[2 * id].update = true;
            }
            if (2 * id + 1 < size) {
                segtree[2 * id + 1].update = true;
            }
        } else {
        }
    }
}
