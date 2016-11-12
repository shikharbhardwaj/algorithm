#include <cmath>
#include <iostream>
int max_pow(int n, int m) {
    int cnt = 0;
    while (n % m == 0) {
        n /= m;
        cnt++;
    }
    return cnt;
}
int max_pow_fact(int n, int m) {
    int accum = 0;
    while (n > 1) {
        accum += n / m;
        n /= m;
    }
    return accum;
}
int get_segtree_size(int n) {
    if (!(n & (n - 1)) && n) {
        return 2 * n;
    }
    while (n & (n - 1)) {
        n = n & (n - 1);
    }
    return n << 2;
}
typedef struct interval {
    int left, right;
    int pow2, pow5;
    int update, x, i;
    int size;
} interval, node;
interval segtree[262144];
int size, N;
void init_segtree(int n) {
    size = get_segtree_size(n);
    N = size / 2;
    int temp;
    for (int i = N; i < N + n; i++) {
        // Leaf nodes
        std::cin >> temp;
        auto &cur = segtree[i];
        cur.pow2 = max_pow(temp, 2);
        cur.pow5 = max_pow(temp, 5);
        cur.right = cur.left = i - N + 1;
        cur.update = cur.i = 0;
        cur.size = 1;
    }
    for (int i = N + n; i < size; i++) {
        // Dummy node
        auto &cur = segtree[i];
        cur.right = cur.left = i - N + 1;
        cur.update = cur.i = cur.size = cur.pow2 = cur.pow5 = 0;
    }
    for (int i = N - 1; i >= 1; i--) {
        // Build the tree
        int l = 2 * i, r = l + 1;
        auto &cur = segtree[i];
        auto &left = segtree[l];
        auto &right = segtree[r];
        cur.left = left.left;
        cur.right = right.right;
        cur.pow2 = left.pow2 + right.pow2;
        cur.pow5 = left.pow5 + right.pow5;
        cur.size = left.size + right.size;
        cur.update = cur.i = cur.x = 0;
    }
}
void apply_update(int id) {
    auto &cur = segtree[id];
    if (cur.update) {
        int add2 = max_pow(cur.x, 2) * cur.size;
        int add5 = max_pow(cur.x, 5) * cur.size;
        if (cur.update == 2) {
            cur.pow2 = cur.pow5 = 0;
            cur.pow2 += max_pow_fact(cur.right - cur.i + 1, 2);
            cur.pow2 -= max_pow_fact(cur.left - cur.i, 2);
            cur.pow5 += max_pow_fact(cur.right - cur.i + 1, 5);
            cur.pow5 -= max_pow_fact(cur.left - cur.i, 5);
        }
        cur.pow2 += add2;
        cur.pow5 += add5;
        if (cur.left != cur.right) {
            if (cur.update == 1) {
                apply_update(2 * id);
                apply_update(2 * id + 1);
            }
            // Fuck previous updates
            auto &left = segtree[2 * id];
            auto &right = segtree[2 * id + 1];
            left.update = right.update = cur.update;
            left.x = right.x = cur.x;
            left.i = cur.i;
            right.i = cur.i;
        }
        cur.update = 0;
    }
}
void query_range(int id, int left, int right, interval &ans) {
    auto &cur = segtree[id];
    apply_update(id);
    if (cur.left > right || cur.right < left) {
        return;
    }
    if (cur.left >= left && cur.right <= right) {
        ans.pow2 += cur.pow2;
        ans.pow5 += cur.pow5;
        return;
    }
    query_range(2 * id, left, right, ans);
    query_range(2 * id + 1, left, right, ans);
    if (cur.left != cur.right) {
        cur.pow2 = segtree[2 * id].pow2 + segtree[2 * id + 1].pow2;
        cur.pow5 = segtree[2 * id].pow5 + segtree[2 * id + 1].pow5;
    }
}
void update_range_mul(int id, int left, int right, int x) {
    if (max_pow(x, 2) == 0 && max_pow(x, 5) == 0)
        return;
    auto &cur = segtree[id];
    apply_update(id);
    if (cur.left > right || cur.right < left) {
        return;
    }
    if (cur.left >= left && cur.right <= right) {
        // Apply the update here
        cur.x = x;
        cur.update = 1;
        apply_update(id);
        return;
    }
    update_range_mul(2 * id, left, right, x);
    update_range_mul(2 * id + 1, left, right, x);
    if (cur.left != cur.right) {
        cur.pow2 = segtree[2 * id].pow2 + segtree[2 * id + 1].pow2;
        cur.pow5 = segtree[2 * id].pow5 + segtree[2 * id + 1].pow5;
    }
}
void update_range_repl(int id, int left, int right, int L, int Y) {
    auto &cur = segtree[id];
    apply_update(id);
    if (cur.left > right || cur.right < left) {
        return;
    }
    if (cur.left >= left && cur.right <= right) {
        // Apply the update here
        cur.x = Y;
        cur.i = L;
        cur.update = 2;
        apply_update(id);
        return;
    }
    update_range_repl(2 * id, left, right, L, Y);
    update_range_repl(2 * id + 1, left, right, L, Y);
    if (cur.left != cur.right) {
        cur.pow2 = segtree[2 * id].pow2 + segtree[2 * id + 1].pow2;
        cur.pow5 = segtree[2 * id].pow5 + segtree[2 * id + 1].pow5;
    }
}

void dump_tree() {
    int level = 0;
    for (int i = 1; i <= N; i *= 2) {
        int j = i;
        while (j != 2 * i) {
            std::cout << "\n[" << segtree[j].left << ", " << segtree[j].right
                      << "] -> (" << segtree[j].pow2 << ", " << segtree[j].pow5
                      << ") :: " << segtree[j].update << " | " << segtree[j].x
                      << " ~ " << segtree[j].i;
            j++;
        }
        std::cout << "\n";
        level++;
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    long long T;
    std::cin >> T;
    while (T--) {
        // std::cout << "Test : " << T << "\n";
        long long N, M;
        std::cin >> N >> M;
        init_segtree(N);
        long long type, L, R, X, Y;
        long long sum = 0;
        for (long long i = 0; i < M; i++) {
            // dump_tree();
            std::cin >> type;
            switch (type) {
            case 1:
                std::cin >> L >> R >> X;
                update_range_mul(1, L, R, X);
                break;
            case 2:
                std::cin >> L >> R >> Y;
                update_range_repl(1, L, R, L, Y);
                break;
            default:
                node ans;
                ans.pow2 = ans.pow5 = 0;
                std::cin >> L >> R;
                query_range(1, L, R, ans);
                // std::cout << "ans : " << std::min(ans.pow2, ans.pow5) <<
                // "\n";
                sum += std::min(ans.pow2, ans.pow5);
                // std::cout << std::min(ans.pow2, ans.pow5) << "\n";
            }
        }
        std::cout << sum << "\n";
    }
}
