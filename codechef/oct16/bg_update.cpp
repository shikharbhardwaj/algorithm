#include <cmath>
#include <iostream>
#include <vector>
template <typename T> T max_pow(T n, T m) {
    T cnt = 0;
    while (n % m == 0) {
        n /= m;
        cnt++;
    }
    return cnt;
}
template <typename T> T max_pow_fact(T n, T m) {
    T accum = 0;
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
    int update;
    size_t left, right;
    size_t pow2, pow5;
    size_t multi2, multi5;
    int size, i;
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
        cur.multi2 = cur.multi5 = 0;
        cur.size = 1;
    }
    for (int i = N + n; i < size; i++) {
        // Dummy node
        auto &cur = segtree[i];
        cur.right = cur.left = i - N + 1;
        cur.update = cur.i = cur.size = cur.pow2 = cur.pow5 = 0;
        cur.multi2 = cur.multi5 = 0;
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
        cur.update = cur.i = 0;
        cur.multi2 = cur.multi5 = 0;
    }
}
void apply_once(int id) {
    auto &cur = segtree[id];
    if (cur.update) {
        int add2 = cur.multi2 * cur.size;
        int add5 = cur.multi5 * cur.size;
        if (cur.update == 2) {
            cur.pow2 = cur.pow5 = 0;
            cur.pow2 += max_pow_fact(cur.right - cur.i + 1, (size_t)2);
            cur.pow2 -= max_pow_fact(cur.left - cur.i, (size_t)2);
            cur.pow5 += max_pow_fact(cur.right - cur.i + 1, (size_t)5);
            cur.pow5 -= max_pow_fact(cur.left - cur.i, (size_t)5);
        }
        cur.pow2 += add2;
        cur.pow5 += add5;
    }
}
void apply_update(int id) {
    auto &cur = segtree[id];
    if (cur.update) {
        apply_once(id);
        if (cur.left != cur.right) {
            // Correct this
            auto &left = segtree[2 * id];
            auto &right = segtree[2 * id + 1];
            if (cur.update == 2) {
                left.update = right.update = cur.update;
                left.multi2 = right.multi2 = cur.multi2;
                left.multi5 = right.multi5 = cur.multi5;
                left.i = right.i = cur.i;
            } else {
                if (left.update == 2)
                    apply_update(2 * id);
                if (right.update == 2)
                    apply_update(2 * id + 1);
                left.update = right.update = cur.update;
                left.multi2 += cur.multi2;
                left.multi5 += cur.multi5;
                right.multi2 += cur.multi2;
                right.multi5 += cur.multi5;
            }
        }
        cur.update = 0;
        cur.multi2 = 0;
        cur.multi5 = 0;
    }
}
void query_range(int id, size_t left, size_t right, interval &ans) {
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
void update_range_mul(int id, size_t left, size_t right, int multi2,
                      int multi5) {
    if (multi2 == 0 && multi5 == 0)
        return;
    auto &cur = segtree[id];
    apply_update(id);
    if (cur.left > right || cur.right < left) {
        return;
    }
    if (cur.left >= left && cur.right <= right) {
        // Apply the update here
        cur.multi2 = multi2;
        cur.multi5 = multi5;
        cur.update = 1;
        apply_update(id);
        return;
    }

    update_range_mul(2 * id, left, right, multi2, multi5);
    update_range_mul(2 * id + 1, left, right, multi2, multi5);
    if (cur.left != cur.right) {
        cur.pow2 = segtree[2 * id].pow2 + segtree[2 * id + 1].pow2;
        cur.pow5 = segtree[2 * id].pow5 + segtree[2 * id + 1].pow5;
    }
}
void update_range_repl(int id, size_t left, size_t right, int L, int multi2,
                       int multi5) {
    auto &cur = segtree[id];
    apply_update(id);
    if (cur.left > right || cur.right < left) {
        return;
    }
    if (cur.left >= left && cur.right <= right) {
        cur.multi2 = multi2;
        cur.multi5 = multi5;
        cur.i = L;
        cur.update = 2;
        apply_update(id);
        return;
    }
    update_range_repl(2 * id, left, right, L, multi2, multi5);
    update_range_repl(2 * id + 1, left, right, L, multi2, multi5);
    if (cur.left != cur.right) {
        cur.pow2 = segtree[2 * id].pow2 + segtree[2 * id + 1].pow2;
        cur.pow5 = segtree[2 * id].pow5 + segtree[2 * id + 1].pow5;
    }
}
int main() {
    int T;
    std::ios_base::sync_with_stdio(false);
    std::cin >> T;
    while (T--) {
        int N, M;
        std::cin >> N >> M;
        init_segtree(N);
        int type, L, R, X, Y;
        int pow2, pow5;
        long long sum = 0;
        std::vector<int> t_vec;
        std::vector<int> l_vec;
        std::vector<int> r_vec;
        std::vector<int> x_vec;
        std::vector<bool> apply;
        for (int i = 0; i < M; i++) {
            // dump_tree();
            std::cin >> type;
            t_vec.push_back(type);
            apply.push_back(true);
            switch (type) {
            case 1:
                std::cin >> L >> R >> X;
                l_vec.push_back(L);
                r_vec.push_back(R);
                x_vec.push_back(X);
                break;
            case 2:
                std::cin >> L >> R >> Y;
                for (size_t j = 0; j < l_vec.size(); j++) {
                    if (apply[j] && l_vec[j] >= L && r_vec[j] <= R)
                        apply[j] = false;
                }
                l_vec.push_back(L);
                r_vec.push_back(R);
                x_vec.push_back(Y);
                break;
            case 3:
                node ans;
                ans.pow2 = ans.pow5 = 0;
                std::cin >> L >> R;
                for (size_t j = 0; j < l_vec.size(); j++) {
                    if (apply[j]) {
                        pow2 = max_pow(x_vec[j], 2);
                        pow5 = max_pow(x_vec[j], 5);
                        if (t_vec[j] == 1) {
                            update_range_mul(1, l_vec[j], r_vec[j], pow2, pow5);
                        } else {
                            update_range_repl(1, l_vec[j], r_vec[j], l_vec[j],
                                              pow2, pow5);
                        }
                    }
                }
                query_range(1, L, R, ans);
                sum += std::min(ans.pow2, ans.pow5);
                t_vec.clear();
                r_vec.clear();
                l_vec.clear();
                x_vec.clear();
                apply.clear();
                break;
            }
        }
        std::cout << sum << "\n";
    }
}
