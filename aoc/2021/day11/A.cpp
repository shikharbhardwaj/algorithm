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

template <typename T>
struct Arr2d {
    int n, m;

    unique_ptr<int[]> data;

    Arr2d(int n, int m) : n(n), m(m) {
        data = make_unique<int[]>(n * m);
    }

    int* operator[](int idx) {
        return &data.get()[idx * m];
    }

    int* begin() {
        return data.get();
    }

    int* end() {
        return data.get() + n * m;
    }
};

void solve() {
    vector<string> grid;
    
    string line;
    while (cin >> line) {
        grid.push_back(line);
    }

    const int n = grid.size(), m = grid[0].size();

    int flash_count = 0;

    auto valid = [&](int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    auto do_step = [&]() {
        Arr2d<bool> flashed(n, m);
        int cur_flashed = 0;

        vector<pair<int, int>> frontier, next;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                grid[i][j] += 1;
                
                if (grid[i][j] > '9') {
                    flashed[i][j] = true;
                    grid[i][j] = '0';
                    frontier.emplace_back(i, j);
                    ++cur_flashed;
                }
            }
        }

        const vector<pair<int, int>> dxy = {{-1, 0},
                                            {1, 0},
                                            {0, -1},
                                            {0, 1},
                                            {1, 1},
                                            {1, -1},
                                            {-1, 1},
                                            {-1, -1}};

        while (!frontier.empty()) {
            auto [x, y] = frontier.back();
            frontier.pop_back();

            for (auto [dx, dy] : dxy) {
                int nx = x + dx, ny = y + dy;

                if (valid(nx, ny) && !flashed[nx][ny]) {
                    grid[nx][ny] += 1;

                    if (grid[nx][ny] > '9') {
                        flashed[nx][ny] = true;
                        grid[nx][ny] = '0';
                        next.emplace_back(nx, ny);
                        ++cur_flashed;
                    }
                }
            }

            if (frontier.empty()) {
                frontier = next;
                next.clear();
            }
        }

        return cur_flashed == n * m;
    };

    // for (size_t i = 0; i < 100; i++) {
    //     auto all_flaheddo_step();
    //     cout << "Step: \t" << i + 1 << "\t, flashes: " << flash_count << endl;
    //     // for (auto row : grid) {
    //     //     cout << row << endl;
    //     // }
    // }
    int i = 0;
    while (!do_step()) ++i;

    cout << "Done on step: " << i + 1 << endl;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif     
    solve();
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}