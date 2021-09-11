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
        
        vector<string> grid(N);

        for (auto& e : grid) cin >> e;

        map<int, int> cnt;

        for (int i = 0; i < N; ++i) {
            int cnt_X = count(begin(grid[i]), end(grid[i]), 'X');
            int cnt_Empty = count(begin(grid[i]), end(grid[i]), '.');
            int cnt_O = count(begin(grid[i]), end(grid[i]), 'O');

            if (cnt_O) continue;
            if (cnt_X + cnt_Empty == N) cnt[cnt_Empty]++;
        }

        for (int j = 0; j < N; ++j) {
            int cnt_X = 0, cnt_Empty = 0, cnt_O = 0;

            for (int i = 0; i < N; ++i) {
                switch (grid[i][j]) {
                    case 'O': cnt_O++; break;
                    case 'X': cnt_X++; break;
                    case '.': cnt_Empty++; break;
                }
            }

            if (cnt_O) continue;
            if (cnt_X + cnt_Empty == N) cnt[cnt_Empty]++;
        }

        if (cnt.empty()) {
            cout << "Case #" << case_num << ": " << "Impossible" << endl;
        } else {
            auto [x, y] = *cnt.begin();
            cout << "Case #" << case_num << ": " << x << " " << y << endl;
        }
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}