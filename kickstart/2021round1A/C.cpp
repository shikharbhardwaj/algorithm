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

int manhattan(pair<int, int> f, pair<int, int> s) {
    return abs(f.first - s.first) + abs(f.second - s.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("ts1_input.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif
    CASE {
        int R, C; cin >> R >> C;

        vector<vector<ll>> grid(R, vector<ll>(C));

        FOR(i, R) {
            FOR(j, C) {
                cin >> grid[i][j];
            }
        }

        auto valid = [&](int i, int j) {
            return i >= 0 && i < R && j >= 0 && j < C;
        };

        ll cost = 0;

        set<pair<ll, pair<int, int>>, greater<pair<ll, pair<int, int>>>> pq;

        FOR(i, R) {
            FOR(j, C) {
                pq.emplace(grid[i][j], make_pair(i, j));
            }
        }

        auto fix_cell = [&](int s_i, int s_j) {
            vector<pair<int, int>> dxy = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

            for (auto [dx, dy] : dxy) {
                int nx = s_i + dx, ny = s_j + dy;

                if (valid(nx, ny) && grid[s_i][s_j] - grid[nx][ny] > 1) {
                    auto diff = grid[s_i][s_j] - grid[nx][ny] - 1;
                    cost += diff;
                    pq.erase(make_pair(grid[nx][ny], make_pair(nx, ny)));
                    grid[nx][ny] += diff;
                    pq.insert(make_pair(grid[nx][ny], make_pair(nx, ny)));
                }
            }
        };

        vector<vector<bool>> visited(R, vector<bool>(C));

        while (!pq.empty()) {
            auto elem = *pq.begin();

            pq.erase(pq.begin());

            auto [v, xy] = elem;
            auto [x, y] = xy;

            if (grid[x][y] != v) continue;

            fix_cell(x, y);
            visited[x][y] = true;
        }

        cout << "Case #" << case_num << ": " << cost << endl;
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}