#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
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
        for (long long j = i; j * i <= 1e6; j++) {
            if (least_prime_factor[j * i] == -1)
                least_prime_factor[j * i] = i;
        }
    }
}
bool is_prime(int n) { return least_prime_factor[n] == n; }
typedef struct interval {
    int left, right;
    int max_prime;
    bool prime = false;
} interval;
interval segtree[2097152];
int a[1000001];
int size, N;
int get_segtree_size(int n) {
    if (!(n & (n - 1))) {
        return 2 * n;
    }
    return 1 << int(ceil(log2(n)) + 1);
}
void build_segtree(int n) {
    size = get_segtree_size(n);
    N = size / 2;
    for (int i = N; i < N + n; i++) {
        segtree[i].right = segtree[i].left = i - N + 1;
        segtree[i].max_prime = least_prime_factor[a[i - N + 1]];
        if (is_prime(a[i - N + 1])) {
            segtree[i].prime = true;
        } else {
            segtree[i].prime = false;
        }
    }
    for (int i = N + n; i < size; i++) {
        segtree[i].right = segtree[i].left = i - N + 1;
        segtree[i].max_prime = 1;
    }
    for (int i = N - 1; i > 0; i--) {
        segtree[i].left = segtree[2 * i].left;
        segtree[i].right = segtree[2 * i + 1].right;
        segtree[i].max_prime =
            std::max(segtree[2 * i].max_prime, segtree[2 * i + 1].max_prime);
        segtree[i].prime = segtree[2 * i].prime && segtree[2 * i + 1].prime;
    }
}
void propogate_upward(int id) {
    if (id == 1)
        return;
    int parent = id / 2;
    int left = 2 * parent;
    int right = left + 1;
    segtree[parent].max_prime =
        std::max(segtree[left].max_prime, segtree[right].max_prime);
    segtree[parent].prime = segtree[left].prime && segtree[right].prime;
    propogate_upward(id / 2);
}
void update_segtree(int id, int left, int right) {
    auto &cur = segtree[id];
    // std::cout << "Hit [" << cur.left << ", " << cur.right << "]\n";
    if (cur.max_prime == 1)
        return;
    if (cur.left > right || cur.right < left)
        return;
    if (cur.left >= left && cur.right <= right) {
        // This is fast
        if (cur.prime) {
            cur.max_prime = 1;
        } else if (cur.left != cur.right) {
            // We need to go the hard way
            update_segtree(2 * id, left, right);
            update_segtree(2 * id + 1, left, right);
        } else {
            a[id - N + 1] /= least_prime_factor[a[id - N + 1]];
            cur.max_prime = least_prime_factor[a[id - N + 1]];
            if (is_prime(a[id - N + 1]))
                cur.prime = true;
        }
        propogate_upward(id);
        return;
    }
    if (cur.left == cur.right)
        return;
    update_segtree(2 * id, left, right);
    update_segtree(2 * id + 1, left, right);
}
void query_segtree(int id, int left, int right, interval &ans) {
    const auto &cur = segtree[id];
    // std::cout << "Hit [" << cur.left << ", " << cur.right << "]\n";
    if (cur.max_prime == 1)
        return;
    if (cur.left > right || cur.right < left)
        return;
    if (cur.left >= left && cur.right <= right) {
        ans.max_prime = std::max(ans.max_prime, cur.max_prime);
        return;
    }
    if (cur.left == cur.right)
        return;
    query_segtree(2 * id, left, right, ans);
    query_segtree(2 * id + 1, left, right, ans);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    gen_least_primes();
    interval ans;
    int T;
    std::cin >> T;
    while (T--) {
        std::vector<int> op;
        int n, M;
        std::cin >> n >> M;
        op.reserve(M / 2);
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        build_segtree(n);
        int type, l, r;
        for (int i = 0; i < M; i++) {
            std::cin >> type >> l >> r;
            switch (type) {
            case 0:
                update_segtree(1, l, r);
                break;
            default:
                ans.max_prime = 1;
                query_segtree(1, l, r, ans);
                op.push_back(ans.max_prime);
            }
            // std::cout << ":: ";
            // std::copy(a + 1, a + n + 1,
            // std::ostream_iterator<int>(std::cout, ", "));
            // std::cout << ":: ";
        }
        std::copy(op.begin(), op.end(),
                  std::ostream_iterator<int>(std::cout, " "));
        std::cout << "\n";
    }
}
