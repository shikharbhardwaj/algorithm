#include <bits/stdc++.h>

#define ONLINE_JUDGE

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

struct Edge {
    int v, w;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
    CASE {
        int n; cin >> n;

        vector<vector<int>> vals(n, vector<int>(n)), weights(n, vector<int>(n));

        FOR(i, n) {
            FOR(j, n) {
                cin >> vals[i][j];
            }
        }

        FOR(i, n) {
            FOR(j, n) {
                cin >> weights[i][j];
            }
        }

        vector<vector<int>> graph(2 * n);

        FOR(i, n) {
            FOR(j, n) {
                if (vals[i][j] == -1) {
                    graph[i].emplace_back(n + j);
                    graph[n + j].emplace_back(i);
                }
            }
        }

        auto get_remaining = [&]() {
            int remaining = 0;

            FOR(i, n) {
                if (graph[i].size() > 1) ++remaining;
            }

            return remaining;
        };

        int cost = 0;

        while (get_remaining()) {
            // Get list of edges which are parts of a cycle.
            // And remove them from largest to smallest.
            vector<vector<bool>> is_critical(n, vector<bool>(n, true));

            vector<vector<bool>> visited(n, vector<bool>(n));
            vector<vector<int>> depth(n, vector<int>(n));

            function<void(int, int)> dfs = [&](int i, int d) {
                visited[u] = true;

                for (auto v : graph[u]) {
                }
            };
        }

    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}