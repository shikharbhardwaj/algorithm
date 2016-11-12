#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
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
bool is_prime(int n) { return least_prime_factor[n] == n; }
typedef struct interval {
    int left, right;
    int max_prime = 1;
} interval;
// Segtree begin
interval segtree[2097152];
int a[1000001];
int size, N;
int get_segtree_size(int n) {
    if (!(n & (n - 1))) {
        return 2 * n;
    }
    return 1 << int(round(log2(n)) + 1);
}
void build_segtree(int n) {
    size = get_segtree_size(n);
    N = size / 2;
    for (int i = N; i < N + n; i++) {
        segtree[i].right = segtree[i].left = i - N + 1;
        segtree[i].max_prime = least_prime_factor[a[i - N + 1]];
    }
    for (int i = N + n; i < size; i++) {
        segtree[i].left = segtree[i].right = i - N;
    }
    for (int i = N - 1; i > 0; i--) {
        segtree[i].left = segtree[2 * i].left;
        segtree[i].right = segtree[2 * i + 1].right;
        segtree[i].max_prime =
            std::max(segtree[2 * i].max_prime, segtree[2 * i + 1].max_prime);
    }
}
void propagate_upward(int id) {
    if (id == 0)
        return;
    int left = 2 * id;
    int right = left + 1;
    segtree[id].max_prime =
        std::max(segtree[left].max_prime, segtree[right].max_prime);
    propagate_upward(id / 2);
}
void update(int id, int left, int right) {
    auto &cur = segtree[id];
    // std::cout << "Update [" << cur.left << ", " << cur.right << "]\n";
    if (cur.max_prime == 1)
        return;
    if (left > cur.right || right < cur.left)
        return;
    if (cur.left >= left && cur.right <= right && cur.left == cur.right) {
        a[cur.left] /= least_prime_factor[a[cur.left]];
        cur.max_prime = least_prime_factor[a[cur.left]];
    }
    auto &l = segtree[2 * id];
    auto &r = segtree[2 * id + 1];
    if (l.right < left)
        update(2 * id + 1, left, right);
    else if (r.left > right)
        update(2 * id, left, right);
    else {
        if (2 * id < size)
            update(2 * id, left, right);
        if (2 * id + 1 < size)
            update(2 * id + 1, left, right);
    }
}
void query(int id, int left, int right, interval &ans) {
    auto &cur = segtree[id];
    if (left > cur.right || right < cur.left)
        return;
    if (cur.left >= left && cur.right <= right) {
        ans.max_prime = std::max(cur.max_prime, ans.max_prime);
        return;
    }
    if (cur.left == cur.right)
        return;
    auto &l = segtree[2 * id];
    auto &r = segtree[2 * id + 1];
    if (l.right < left)
        query(2 * id + 1, left, right, ans);
    else if (r.left > right)
        query(2 * id, left, right, ans);
    else {
        query(2 * id, left, right, ans);
        query(2 * id + 1, left, right, ans);
    }
}
// Segtree end
int main() {
    std::ios_base::sync_with_stdio(false);
    int T, n, M;
    interval ans;
    std::cin >> T;
    gen_least_primes();
    while (T--) {
        int type, L, R;
        std::cin >> n >> M;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        build_segtree(n);
        for (int i = 0; i < M; i++) {
            std::cin >> type >> L >> R;
            if (type == 0) {
                update(1, L, R);
                for (int i = N + L - 1; i < N + R; i += 2)
                    propagate_upward(i / 2);
            } else {
                ans.max_prime = 1;
                query(1, L, R, ans);
                std::cout << ans.max_prime << " ";
            }
            // std::cout << "\n";
            // std::copy(a + 1, a + n + 1, std::ostream_iterator<int>(std::cout,
            // ", "));
        }
        std::cout << "\n";
    }
}
