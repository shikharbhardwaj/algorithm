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

vector<string> split(const string& str, char delim) {
    istringstream ss(str);

    vector<string> tokens;
    string token;
    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
}


enum class FoldAxis { FOLD_X, FOLD_Y };

using Fold = pair<FoldAxis, int>;

// struct Fold {
//     FoldAxis axis;
//     int co_ord;

//     Fold() = default;
//     Fold(FoldAxis axis, int co_ord) : axis(axis), co_ord(co_ord) {}
// };

ostream& operator<< (ostream& os, const Fold& fold) {
    os << "Fold[" << (int) fold.first << ", " << fold.second << "]";

    return os;
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
    vector<pair<int, int>> points;
    vector<Fold> folds;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        auto space_split = split(line, ' ');

        if (space_split[0] == "fold") {
            auto fold_values = split(space_split[2], '=');

            auto fold_axis = (fold_values[0] == "x") ? FoldAxis::FOLD_X : FoldAxis::FOLD_Y;
            auto fold_coord = stoi(fold_values[1]);
            folds.emplace_back(fold_axis, fold_coord);
        } else {
            auto point_values = split(space_split[0], ',');

            points.emplace_back(stoi(point_values[0]), stoi(point_values[1]));
        }
    }

    int max_x = max_element(begin(points), end(points), [](const pii& p0, const pii& p1) {
        return p0.first < p1.first;
    })->first;

    int max_y = max_element(begin(points), end(points), [](const pii& p0, const pii& p1) {
        return p0.second < p1.second;
    })->second;

    auto new_grid = [&]() {
        return vector<vector<bool>>(max_y + 1, vector<bool>(max_x + 1));
    };

    auto grid = new_grid();
    for (auto [x, y] : points) {
        grid[y][x] = 1;
    }

    auto show_grid = [&]() {
        for (auto row : grid) {
            cout << row << endl;
        }
    };

    auto reverse_columns = [&]() {
        int left = 0, right = max_x;
    
        while (left < right) {
            for (int i = 0; i <= max_y; ++i) {
                swap(grid[i][left], grid[i][right]);
            }
            ++left, --right;
        }
    };

    auto reverse_rows = [&]() {
        reverse(ALL(grid));
    };

    auto fold_x = [&](int coord) {
        if (coord < max_x / 2) {
            cout << "Reversing columns" << endl;
            reverse_columns();
            coord = max_x - coord;
        }

        int prev_max_x = max_x;
        int diff = max_x - coord;
        int copy_col_cnt = max_x - 2 * diff;
        int overlap_col_cnt = diff;

        max_x = max(max_x - coord, coord) - 1;
        auto next_grid = new_grid();

        cout << "Folding along x=" << coord << endl;
        // show_grid();

        // Copy lines first.
        int cur_col = 0;
        int new_col = 0, prev_col = 0;

        while (cur_col < copy_col_cnt) {
            for (int y = 0; y <= max_y; ++y) {
                next_grid[y][new_col] = grid[y][prev_col];
            }
            ++new_col;
            ++prev_col;
            ++cur_col;
        }


        cout << "Diff: " << diff << endl;
        cout << "Overlap col count: " << overlap_col_cnt << endl;
        cout << "Copy col count: " << copy_col_cnt << endl;

        prev_col = prev_max_x;

        while (cur_col <= max_x) {
            for (int i = 0; i <= max_y; ++i) {
                next_grid[i][cur_col] = max(grid[i][cur_col], grid[i][prev_col]);
            }
            ++cur_col;
            --prev_col;
        }

        grid = next_grid;
        show_grid();
    };

    auto fold_y = [&](int coord) {
        if (coord < max_y / 2) {
            cout << "Reversing rows" << endl;
            reverse_rows();
            coord = max_y - coord;
        }

        int prev_max_y = max_y;
        int diff = max_y - coord;
        int copy_row_cnt = max_y - 2 * diff;
        int overlap_row_cnt = diff;

        max_y = max(max_y - coord, coord) - 1;
        auto next_grid = new_grid();

        cout << "Folding along y=" << coord << endl;
        // show_grid();

        // Copy lines first.
        int cur_row = 0;
        int new_row = 0, prev_row = 0;

        while (cur_row < copy_row_cnt) {
            for (int x = 0; x <= max_x; ++x) {
                next_grid[new_row][x] = grid[prev_row][x];
            }
            ++new_row;
            ++prev_row;
            ++cur_row;
        }


        cout << "Diff: " << diff << endl;
        cout << "Overlap col count: " << overlap_row_cnt << endl;
        cout << "Copy col count: " << copy_row_cnt << endl;

        prev_row = prev_max_y;

        while (cur_row <= max_y) {
            for (int i = 0; i <= max_x; ++i) {
                next_grid[cur_row][i] = max(grid[cur_row][i], grid[prev_row][i]);
            }
            ++cur_row;
            --prev_row;
        }

        grid = next_grid;
        show_grid();
    };

    cout << "max_y: " << max_y << endl;
    cout << "Initial grid: " << endl;
    show_grid();

    // Do a fold.
    for (auto [axis, coord] : folds) {
        switch (axis) {
            case FoldAxis::FOLD_X: fold_x(coord); break;
            case FoldAxis::FOLD_Y: fold_y(coord); break;
        }
        // break;
    }

    cout << "Final: " << endl;
    show_grid();

    int ans = 0;

    for (int y = 0; y <= max_y; ++y) {
        for (int x = 0; x <= max_x; ++x) {
            ans += grid[y][x];
        }
    }

    // Remove all rows with 0 values.
    cout << ans << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}