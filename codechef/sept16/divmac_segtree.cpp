#include <cmath>
#include <iostream>
#include <vector>
// Aim : Pass subtask 2
//
// Create a segtree having the max_updates that the range can have
// Once, this becomes 0, no updates, queries in O(1)

int least_prime_factor[1000001];
int nums[1000001];
int size, N;
typedef struct interval_info {
    int left, right;
    int max_upates_remaining = 0;
} interval_info, interval;
interval segtree[1048576];
int get_segtree_size(int n) {
    if (n & (n - 1) && !n) {
        return 2 * n;
    } else {
        return 1 << ((int)log2(n) + 1);
    }
}
void init_segtree(int n) {
    size = get_segtree_size(n);
    N = size / 2;
    for (int i = N; i < N + n; i++) {
        int id = i - N + 1;
        auto cur_elem = nums[id];
        while (cur_elem != 1) {
            cur_elem /= least_prime_factor[cur_elem];
            segtree[i].max_upates_remaining++;
        }
        segtree[i].left = segtree[i].right = id;
    }
    for (int i = N + n; i < size; i++) {
        segtree[i].left = segtree[i].right = i - N + 1;
    }
    for (int i = N - 1; i > 0; i--) {
        auto &left = segtree[2 * i];
        auto &right = segtree[2 * i + 1];
        segtree[i].max_upates_remaining =
            std::max(left.max_upates_remaining, right.max_upates_remaining);
        segtree[i].left = left.left;
        segtree[i].right = right.right;
    }
}
void update_segtree(int left, int right) {
    for (int i = left; i <= right; i++) {
        if (segtree[i + N - 1].max_upates_remaining)
            segtree[i + N - 1].max_upates_remaining--;
    }
    for (int i = N - 1; i > 0; i--) {
        auto &left = segtree[2 * i];
        auto &right = segtree[2 * i + 1];
        segtree[i].max_upates_remaining =
            std::max(left.max_upates_remaining, right.max_upates_remaining);
    }
}
void query_segtree(int id, interval &ans) {
    auto &cur = segtree[id];
    // std::cout << "[" << cur.left << ", " << cur.right << "] :: ";
    if (cur.left > ans.right || cur.right < ans.left)
        return;
    if (ans.left <= cur.left && ans.right >= cur.right) {
        ans.max_upates_remaining += cur.max_upates_remaining;
        return;
    }
    if (cur.left == cur.right)
        return;
    auto &left = segtree[2 * id];
    auto &right = segtree[2 * id + 1];
    if (left.right < ans.left)
        query_segtree(2 * id + 1, ans);
    else if (right.left > ans.right)
        query_segtree(2 * id, ans);
    else {
        query_segtree(2 * id, ans);
        query_segtree(2 * id + 1, ans);
    }
}
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
int main() {
    std::ios_base::sync_with_stdio(false);
    int T, N, M;
    interval ans;
    std::cin >> T;
    gen_least_primes();
    while (T--) {
        int type, L, R;
        std::cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            std::cin >> nums[i];
        }
        init_segtree(N);
        for (int i = 0; i < M; i++) {
            std::cin >> type >> L >> R;
            ans.left = L, ans.right = R;
            query_segtree(1, ans);
            if (type == 0) {
                if (ans.max_upates_remaining != 0)
                    for (int i = L; i <= R; i++) {
                        nums[i] /= least_prime_factor[nums[i]];
                    }
            } else {
                int result = 1;
                if (ans.max_upates_remaining != 0)
                    for (int i = L; i <= R; i++) {
                        result = std::max(result, least_prime_factor[nums[i]]);
                    }
                std::cout << result << " ";
            }
        }
        std::cout << "\n";
    }
}
