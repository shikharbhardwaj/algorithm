#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)
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
    vector<string> grid;

    string line;
    while (getline(cin, line)) {
        grid.push_back(line);
    }

    int num_rows = grid.size();
    int num_cols = grid[0].size();

    vector<string> left_max, right_max, top_max, bottom_max;
    left_max = right_max = top_max = bottom_max = grid;

    vector<vector<int>> left_max_idx, right_max_idx, top_max_idx, bottom_max_idx;
    left_max_idx = right_max_idx = top_max_idx = bottom_max_idx = vector<vector<int>>(num_rows, vector<int>(num_cols));

    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            left_max_idx[i][j] = j;
            right_max_idx[i][j] = j;
            top_max_idx[i][j] = i;
            bottom_max_idx[i][j] = i;
        }
    }

    vector<vector<int>> row_stacks;
    row_stacks.assign(num_cols, {0});

    for (int i = 1; i < num_rows; ++i) {
        vector<int> col_stack = {0};
        for (int j = 1; j < num_cols; ++j) {
            while (!col_stack.empty() && grid[i][col_stack.back()] < grid[i][j]) {
                col_stack.pop_back();
            }

            if (!col_stack.empty()) {
                left_max_idx[i][j] = col_stack.back();
                left_max[i][j] = grid[i][col_stack.back()];
            } else {
                left_max_idx[i][j] = 0;
                left_max[i][j] = -1;
            }
            col_stack.push_back(j);

            auto& row_stack = row_stacks[j];

            while (!row_stack.empty() && grid[row_stack.back()][j] < grid[i][j]) {
                row_stack.pop_back();
            }

            if (!row_stack.empty()) {
                top_max_idx[i][j] = row_stack.back();
                top_max[i][j] = grid[row_stack.back()][j];
            } else {
                top_max_idx[i][j] = 0;
                top_max[i][j] = -1;
            }
            row_stack.push_back(i);
        }
    }

    row_stacks.assign(num_cols, {num_rows-1});
    for (int i = num_rows - 2; i >= 0; --i) {
        vector<int> col_stack = {num_cols-1};
        for (int j = num_cols - 2; j >= 0; --j) {
            while (!col_stack.empty() && grid[i][col_stack.back()] < grid[i][j]) {
                col_stack.pop_back();
            }

            if (!col_stack.empty()) {
                right_max_idx[i][j] = col_stack.back();
                right_max[i][j] = grid[i][col_stack.back()];
            } else {
                right_max_idx[i][j] = num_cols - 1;
                right_max[i][j] = 0;
            }
            col_stack.push_back(j);

            auto& row_stack = row_stacks[j];

            while (!row_stack.empty() && grid[row_stack.back()][j] < grid[i][j]) {
                row_stack.pop_back();
            }

            if (!row_stack.empty()) {
                bottom_max_idx[i][j] = row_stack.back();
                bottom_max[i][j] = grid[row_stack.back()][j];
            } else {
                bottom_max_idx[i][j] = num_rows - 1;
                bottom_max[i][j] = 0;
            }
            row_stack.push_back(i);
        }
    }

    auto printIdxGrid = [&](const vector<vector<int>>& g) {
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                cout << g[i][j];
            }
            cout << endl;
        }
        cout << endl;
    };
    auto printGrid = [&](const vector<vector<int>>& g, bool col) {
        for (int i = 0; i < num_rows; ++i) {
            for (int j = 0; j < num_cols; ++j) {
                if (col) cout << grid[i][g[i][j]];
                else     cout << grid[g[i][j]][j];
            }
            cout << endl;
        }
        cout << endl;
    };

    printGrid(left_max_idx, true);
    printGrid(top_max_idx, false);
    printGrid(right_max_idx, true);
    printGrid(bottom_max_idx, false);

    int exterior = 2 * (num_rows + num_cols - 2);
    vector<tuple<vector<string>, int, int>> dxy =  {{bottom_max, 0, 1}, {top_max, 0, -1}, {right_max, 1, 0}, {left_max, -1, 0}};

    cout << exterior << endl;

    auto score = [&](int i, int j) {
        int left_score = (j - left_max_idx[i][j]) ;
        int top_score = (i - top_max_idx[i][j]) ;
        int bottom_score = (bottom_max_idx[i][j] - i) ;
        int right_score = (right_max_idx[i][j] - j) ;

        cout << "Scores: " << vector<int>{left_score, top_score, right_score, bottom_score} << endl;

        return top_score * left_score * right_score * bottom_score;
    };

    int ans = exterior;

    int max_score = 0;

    for (int i = 1; i < num_rows - 1; ++i) {
        for (int j = 1; j < num_cols - 1; ++j) {
            int cur_score = score(i, j);
            max_score = max(max_score, cur_score);
            // cout << i << ", " << j << " : " << cur_score << endl;

            for (auto [dp, dx, dy] : dxy) {
                if (dp[i + dy][j + dx] < grid[i][j]) {
                    ++ans;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    cout << max_score << endl;

    // printIdxGrid(left_max_idx);
    // printIdxGrid(top_max_idx);
    // printIdxGrid(right_max_idx);
    // printIdxGrid(bottom_max_idx);

    // cout << score(3, 2) << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}