#include <iostream>
typedef long long ll;
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(static_cast<std::ostream *>(nullptr));
}
int fib_n(int);
// Elementary data begin
const int max_n = 131072;
const int mod = 1e9 + 7;
int elems[max_n];
int N, M, p, Y;
// Elementay data end
// Segtree begin
typedef struct interval_info {
    // The node of the segment tree
    int fib_sum, fib_sum_m1, fib_sum_p1;
    int l, r;
} interval_info;
interval_info seg_tree[2 * max_n];
void combine_interval_info(const interval_info &left,
                           const interval_info &right,
                           interval_info *combined) {
    // Combination logic for the nodes
    combined->fib_sum = (((ll)left.fib_sum + (ll)right.fib_sum +
                          (ll)left.fib_sum * (ll)right.fib_sum_p1 +
                          (ll)left.fib_sum_m1 * (ll)right.fib_sum) %
                         mod);
    combined->fib_sum_p1 = (((ll)left.fib_sum_p1 + (ll)right.fib_sum_p1 +
                             (ll)left.fib_sum_p1 * (ll)right.fib_sum_p1 +
                             (ll)left.fib_sum * (ll)right.fib_sum) %
                            mod);
    combined->fib_sum_m1 = (((ll)left.fib_sum_m1 + (ll)right.fib_sum_m1 +
                             (ll)left.fib_sum * (ll)right.fib_sum +
                             (ll)left.fib_sum_m1 * (ll)right.fib_sum_m1) %
                            mod);
}
void init_seg_tree() {
    // Fill the leaf nodes
    for (int i = 0; i < N; i++) {
        seg_tree[max_n + i].fib_sum = fib_n(elems[i]);
        seg_tree[max_n + i].fib_sum_m1 = fib_n(elems[i] - 1);
        seg_tree[max_n + i].fib_sum_p1 = fib_n(elems[i] + 1);
        seg_tree[max_n + i].l = seg_tree[max_n + i].r = i + 1;
    }
    // Fill the children of the leaves with sentinels
    for (int i = N; i < max_n; i++) {
        seg_tree[max_n + i].fib_sum = seg_tree[max_n + i].fib_sum_m1 =
            seg_tree[max_n + i].fib_sum_p1 = 0;
        seg_tree[max_n + i].l = seg_tree[max_n + i].r = i + 1;
    }
    // Build the tree
    for (int i = max_n - 1; i >= 1; i--) {
        int left = i * 2;
        int right = left + 1;
        seg_tree[i].l = seg_tree[left].l;
        seg_tree[i].r = seg_tree[right].r;
        combine_interval_info(seg_tree[left], seg_tree[right], &seg_tree[i]);
    }
}
void propogate_point_update(int x, int y) {
    x = x + max_n - 1; // The corresponding index in the segment tree
    seg_tree[x].fib_sum = fib_n(y);
    seg_tree[x].fib_sum_m1 = fib_n(y - 1);
    seg_tree[x].fib_sum_p1 = fib_n(y + 1);
    x /= 2;
    while (x >= 1) {
        int left = x * 2;
        int right = left + 1;
        combine_interval_info(seg_tree[left], seg_tree[right], &seg_tree[x]);
        x /= 2;
    }
}
// Segtree current state data
interval_info ans, temp;
// Current interval state data
int search_left, search_right;
void query(int node) {
    if (search_left <= seg_tree[node].l && search_right >= seg_tree[node].r) {
        // This node matches
        combine_interval_info(ans, seg_tree[node], &temp);
        ans = temp;
        return;
    }
    int left = node * 2;
    int right = left + 1;
    if (search_left <= seg_tree[left].r)
        query(left);
    if (search_right >= seg_tree[right].l)
        query(right);
}
// Segtree end
// Fib begin
const int mat[2][2] = {{1, 1}, {1, 0}};
void multiply(int first[2][2], const int second[2][2]) {
    // Multiply the two matrices and store the result in the first matrix
    long long a, b, c, d;
    a = (((ll)first[0][0] * (ll)second[0][0] +
          (ll)first[0][1] * (ll)second[1][0]) %
         mod);
    b = (((ll)first[0][0] * (ll)second[0][1] +
          (ll)first[0][1] * (ll)second[1][1]) %
         mod);
    c = (((ll)first[1][0] * (ll)second[0][0] +
          (ll)first[1][1] * (ll)second[1][0]) %
         mod);
    d = (((ll)first[1][0] * (ll)second[0][1] +
          (ll)first[1][1] * (ll)second[1][1]) %
         mod);
    first[0][0] = a;
    first[0][1] = b;
    first[1][0] = c;
    first[1][1] = d;
}
void bin_pow(int in[2][2], int n) {
    if (n == 0 || n == 1) {
        return;
    }
    bin_pow(in, n / 2);
    multiply(in, in);
    if (n % 2 == 1) {
        multiply(in, mat);
    }
}
int fib_n(int n) {
    // The nth fibonacci number in O(lg n)
    int mat[2][2] = {{1, 1}, {1, 0}};
    if (n == 0) {
        return 0;
    }
    bin_pow(mat, n - 1);
    return mat[0][0];
}

// Fib end
int main() {
    char ch;
    fast_io();
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> elems[i];
    }
    for (int i = N; i < max_n; i++) {
        elems[i] = 0;
    }
    init_seg_tree();
    while (M--) {
        std::cin >> ch;
        switch (ch) {
        case 'Q': {
            std::cin >> search_left;
            std::cin >> search_right;
            ans.fib_sum = ans.fib_sum_m1 = ans.fib_sum_p1 = 0;
            query(1); // Query from the root
            std::cout << ans.fib_sum << "\n";
            break;
        }
        default: {
            std::cin >> p >> Y;
            propogate_point_update(p, Y);
        }
        }
    }
}
