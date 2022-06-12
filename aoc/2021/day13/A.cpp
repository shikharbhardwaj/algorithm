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

            auto fold_axis = (fold_values[0] == "x") ? FoldAxis::FOLD_Y : FoldAxis::FOLD_X;
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

    auto fold_y = [&](int coord) {
        max_y = max(max_y - coord, coord);
        auto next_grid = new_grid();

        cout << "Folding along x=" << coord << endl;
        // show_grid();

        // Copy lines first.
        int new_col = 0, prev_col = max_x;

        while (prev_col >= coord) {
            for (int y = 0; y <= max_y; ++y) {
                next_grid[y][new_col] = grid[y][prev_col];
            }
            ++new_col;
            --prev_col;
        }

        for (int y = 0; y <= max_y; ++y) {
            for (int x = 0; x < coord; ++x) {
                next_grid[y][x] = max(next_grid[y][x], grid[y][x]);
            }
        }

        grid = next_grid;
    };

    auto fold_x = [&](int coord) {
        max_x = max(max_x - coord, coord);
        auto next_grid = new_grid();

        cout << "Folding along y=" << coord << endl;
        // show_grid();

        // Copy lines first.
        int new_line = 0, prev_line = max_y;

        while (prev_line >= coord) {
            for (int x = 0; x <= max_x; ++x) {
                next_grid[new_line][x] = grid[prev_line][x];
            }
            ++new_line;
            --prev_line;
        }

        for (int y = 0; y < coord; ++y) {
            for (int x = 0; x <= max_x; ++x) {
                next_grid[y][x] = max(next_grid[y][x], grid[y][x]);
            }
        }

        grid = next_grid;
    };

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
    // cout << ans << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}