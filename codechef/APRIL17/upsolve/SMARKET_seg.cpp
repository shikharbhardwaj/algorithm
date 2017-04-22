#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define TEST                                                                   \
    int T;                                                                     \
    std::cin >> T;                                                             \
    while (T--)
using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using namespace std;
struct node {
    int l, r;
    vector<int> cnt;
    node() : l(0), r(0) {}
};
node tree[(1 << 18) + 1];
int pref_cnt[(1 << 17) + 1];
int suff_cnt[(1 << 17) + 1];
int ar[100005];
size_t N, sz, X;

void combine(size_t id) {
    auto &left = tree[2 * id];
    auto &right = tree[2 * id + 1];
    tree[id].l = left.l;
    tree[id].r = right.r;
    auto l_cnt = left.cnt;
    auto r_cnt = right.cnt;
    if (ar[left.r] == ar[right.l]) {
        // Number of elements in the left interval
        int n1 = pref_cnt[left.r];
        if (n1 > left.r - left.l + 1) {
            n1 = left.r - left.l + 1;
        }
        if (n1 > 0)
            l_cnt.erase(lower_bound(l_cnt.begin(), l_cnt.end(), n1));
        int n2 = suff_cnt[right.l];
        if (n2 > right.r - right.l + 1) {
            n2 = right.r - right.l + 1;
        }
        if (n2 > 0)
            r_cnt.erase(lower_bound(r_cnt.begin(), r_cnt.end(), n2));
        r_cnt.push_back(n1 + n2);
    }
    tree[id].cnt.clear();
    // Linear time hit
    merge(l_cnt.begin(), l_cnt.end(), r_cnt.begin(), r_cnt.end(),
          back_inserter(tree[id].cnt));
}

void init() {
    X = 1 << int(ceil(log2(N)));
    sz = X * 2;
    for (size_t i = X; i < X + N; ++i) {
        tree[i].l = tree[i].r = i - X + 1;
        tree[i].cnt = {1};
    }
    for (size_t i = X + N; i < sz; ++i) {
        tree[i].l = tree[i].r = i - X + 1;
    }
    for (size_t i = X - 1; i > 0; --i) {
        combine(i);
    }
}

int query(int i, int l, int r, int k){
    const auto& cur = tree[i];
    if(cur.l > r || cur.r < l){
        return 0;
    } else if(cur.l >= l && cur.r <= r){
        // Check for left extension
        return cur.cnt.end() - lower_bound(cur.cnt.begin(), cur.cnt.end(), k);
    }
    return query(2 * i, l, r, k) + query(2 * i + 1, l, r, k);
}

int main() {
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif
    pref_cnt[0] = 0;
    suff_cnt[0] = 0;
    TEST {
        int Q;
        cin >> N >> Q;
        for (size_t i = 0; i < N; ++i) {
            cin >> ar[i + 1];
        }
        pref_cnt[1] = 1;
        suff_cnt[N] = 1;
        int cur_f = ar[1];
        int cur_b = ar[N];
        for (size_t i = 2; i <= N; ++i) {
            if (ar[i] == cur_f) {
                pref_cnt[i] = pref_cnt[i - 1] + 1;
            } else {
                pref_cnt[i] = 1;
                cur_f = ar[i];
            }
            if (ar[N - i + 1] == cur_b) {
                suff_cnt[N - i + 1] = suff_cnt[N - i + 2] + 1;
            } else {
                suff_cnt[N - i + 1] = 1;
                cur_b = ar[N - i + 1];
            }
        }
        init();
        int l, r, k;
        FOR(i, Q) {
            cin >> l >> r >> k;
            cout << query(1, l, r, k) << endl;
        }
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);   // restore
    cout.rdbuf(coutbuf); // restore
#endif
}
