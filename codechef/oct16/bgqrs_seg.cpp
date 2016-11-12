#include <cmath>
#include <iostream>
int pow2_fact(int n) {
    int ans = 0;
    while (n / 2 > 0) {
        ans += n / 2;
        n /= 2;
    }
    return ans;
}
int pow5_fact(int n) {
    int ans = 0;
    while (n / 5 > 0) {
        ans += n / 5;
        n /= 5;
    }
    return ans;
}
int max5(int n) {
    int cnt = 0;
    while (n % 5 == 0) {
        n /= 5;
        cnt++;
    }
    return cnt;
}
int max2(int n) {
    int cnt = 0;
    while (n % 2 == 0) {
        n /= 2;
        cnt++;
    }
    return cnt;
}
// Segtree begin
typedef struct node {
    int left, right;
    int pow2, pow5;
    int update, i, x;
    int size;
} node;
int get_segtree_size(int n) {
    if (!(n & (n - 1)) && n) {
        return 2 * n;
    }
    while (n & (n - 1)) {
        n = n & (n - 1);
    }
    return n << 2;
}
node segtree[262144];
int size, N;
int ar[100005];
void init_segtree(int n) {
    size = get_segtree_size(n);
    N = size / 2;
    for (int i = N; i < N + n; i++) {
        int id = i - N + 1;
        int val = ar[id];
        segtree[i].left = segtree[i].right = id;
        segtree[i].pow2 = max2(val);
        segtree[i].pow5 = max5(val);
        segtree[i].size = 1;
        segtree[i].update = 0;
    }
    for (int i = N + n; i < size; i++) {
        segtree[i].left = segtree[i].right = (i - N + 1);
        segtree[i].pow2 = segtree[i].pow5 = 0;
        segtree[i].size = 0;
        segtree[i].update = 0;
    }
    for (int i = N - 1; i >= 1; i--) {
        auto &left = segtree[2 * i];
        auto &right = segtree[2 * i + 1];
        auto &cur = segtree[i];
        cur.left = left.left;
        cur.right = right.right;
        cur.pow2 = left.pow2 + right.pow2;
        cur.pow5 = left.pow5 + right.pow5;
        cur.size = left.size + right.size;
        cur.update = 0;
    }
}
void apply_update(int id) {
    auto &cur = segtree[id];
    if (cur.update) {
        // std::cout << "\nUpdate [" << cur.left << ", " << cur.right << "] ->
        // ("
        //<< cur.pow2 << ", " << cur.pow5 << ") :: " << cur.update
        //<< ", " << cur.x;
        int pow2 = max2(cur.x) * cur.size;
        int pow5 = max5(cur.x) * cur.size;
        if (cur.update == 2) {
            cur.pow2 = cur.pow5 = 0;
            cur.pow2 += pow2_fact(cur.i + cur.size - 1);
            cur.pow2 -= pow2_fact(cur.i - 1);
            cur.pow5 += pow5_fact(cur.i + cur.size - 1);
            cur.pow5 -= pow5_fact(cur.i - 1);
        }
        cur.pow2 += pow2;
        cur.pow5 += pow5;
        if (cur.left != cur.right) {
            auto &left = segtree[2 * id];
            auto &right = segtree[2 * id + 1];
            if (cur.update == 1) {
                left.update = right.update = 1;
                left.x = right.x = cur.x;
            } else {
                left.update = right.update = 2;
                left.x = right.x = cur.x;
                left.i = cur.i;
                right.i = cur.i + left.size;
            }
        }
    }
    cur.update = 0;
}
void query_range(int id, int l, int r, node &ans) {
    apply_update(id);
    auto &cur = segtree[id];
    if (cur.left > r || cur.right < l) {
        return;
    }
    if (cur.left >= l && cur.right <= r) {
        ans.pow2 += cur.pow2;
        ans.pow5 += cur.pow5;
        return;
    }
    query_range(2 * id, l, r, ans);
    query_range(2 * id + 1, l, r, ans);
    if (cur.left != cur.right) {
        cur.pow2 = segtree[2 * id].pow2 + segtree[2 * id + 1].pow2;
        cur.pow5 = segtree[2 * id].pow5 + segtree[2 * id + 1].pow5;
    }
}
void update_range_mul(int id, int l, int r, int x) {
    if (max5(x) == 0 && max2(x) == 0) {
        return;
    }
    apply_update(id);
    auto &cur = segtree[id];
    if (cur.left > r || cur.right < l) {
        return;
    }
    if (cur.left >= l && cur.right <= r) {
        cur.x = x;
        cur.update = 1;
        apply_update(id);
        return;
    }
    update_range_mul(2 * id, l, r, x);
    update_range_mul(2 * id + 1, l, r, x);
    if (cur.left != cur.right) {
        cur.pow2 = segtree[2 * id].pow2 + segtree[2 * id + 1].pow2;
        cur.pow5 = segtree[2 * id].pow5 + segtree[2 * id + 1].pow5;
    }
}
void update_range_repl(int id, int l, int r, int i, int x) {
    apply_update(id);
    auto &cur = segtree[id];
    if (cur.left > r || cur.right < l) {
        return;
    }
    if (cur.left >= l && cur.right <= r) {
        cur.x = x;
        cur.update = 2;
        cur.i = cur.left - i + 1;
        apply_update(id);
        return;
    }
    update_range_repl(2 * id, l, r, i, x);
    update_range_repl(2 * id + 1, l, r, i, x);
    if (cur.left != cur.right) {
        cur.pow2 = segtree[2 * id].pow2 + segtree[2 * id + 1].pow2;
        cur.pow5 = segtree[2 * id].pow5 + segtree[2 * id + 1].pow5;
    }
}
// Segtree end
void indent(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << " ";
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
        for (long long i = 1; i <= N; i++) {
            std::cin >> ar[i];
        }
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
