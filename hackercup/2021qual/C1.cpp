#include <bits/stdc++.h>

// #define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define FOR1(i, n) for(int i = 1; i <= n; ++i)
#define TEST int T; std::cin >> T; while(T--)
#define CASE int C; std::cin >> C; FOR1(case_num, C)
#define ALL(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using namespace std;


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif     
    int T; cin >> T;

    for (size_t case_num = 1; case_num <= T; case_num++) {
        int N; cin >> N;

        vector<int> value(N);

        for (auto& e : value) cin >> e;

        vector<vector<int>> tree(N);
        for (int i = 0; i < N - 1; ++i) {
            int u, v; cin >> u >> v;

            tree[u - 1].push_back(v - 1);
            tree[v - 1].push_back(u - 1);
        }

        function<int(int, int)> visit = [&](int u, int p) {
            int best0 = 0, best1 = 0;

            for (auto v : tree[u]) {
                if (v == p) continue;

                int cur = visit(v, u);

                if (cur > best0) {
                    best1 = best0;
                    best0 = cur;
                } else if (cur > best1) {
                    best1 = cur;
                }
            }

            if (u == 0) best0 += best1;

            return best0 + value[u];
        };

        int ans = visit(0, -1);

        cout << "Case #" << case_num <<  ": " << ans << endl;
    }
    
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}