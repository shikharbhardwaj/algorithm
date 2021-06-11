/*
01111000
00001000
00000000

ans = 2


Brute: Lets assume (i, j) to be the end of the shorter segment.

for cell in matrix:
    for length in range(2, max(n, m)):
        for dir in ['px', 'py', 'nx', 'ny']:
            for pdir in get_perp_dir(dir):
                seg0_end = 
                segment = 
                if exists(segment):
                    ++count
            If a segment exists, check for perpendicular segment to current direction. (2 possibilities)
            Must be 2 * length in size.

O(R * C * max(R, C))
*/

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

using Cell = pair<int, int>;

enum class DIRECTION {
    POSITIVE_X = 0,
    NEGATIVE_X = 1,
    POSITIVE_Y = 2,
    NEGATIVE_Y = 3
};

Cell apply(const Cell& origin, DIRECTION direction, int length) {
    switch (direction) {
        case DIRECTION::POSITIVE_X: return {origin.first + length, origin.second};
        case DIRECTION::NEGATIVE_X: return {origin.first - length, origin.second};
        case DIRECTION::POSITIVE_Y: return {origin.first, origin.second + length};
        case DIRECTION::NEGATIVE_Y: return {origin.first, origin.second - length};
    }

    return {0, 0};
}

vector<DIRECTION> get_perpendicular_directions(DIRECTION direction) {
    switch (direction) {
        case DIRECTION::POSITIVE_X:
        case DIRECTION::NEGATIVE_X: return {DIRECTION::POSITIVE_Y, DIRECTION::NEGATIVE_Y};
        case DIRECTION::POSITIVE_Y:
        case DIRECTION::NEGATIVE_Y: return {DIRECTION::POSITIVE_X, DIRECTION::NEGATIVE_X};
    }

    return {};
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
    CASE {
        int n, m; cin >> n >> m;

        vector<vector<int>> mat(n, vector<int>(m));

        FOR(i, n) {
            FOR(j, m) {
                cin >> mat[i][j];
            }
        }

        auto valid = [&](const Cell& cell) {
            auto [i, j] = cell;

            return i >= 0 && i < n && j >= 0 && j < m;
        };

        auto at = [&](const Cell& cell) {
            auto [i, j] = cell;

            return mat[i][j];
        };

        auto col_pref = mat;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                col_pref[i][j] += col_pref[i - 1][j];
            }
        }

        auto row_pref = mat;

        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                row_pref[i][j] += row_pref[i][j - 1];
            }
        }

        function<bool(Cell, Cell, DIRECTION)> segment_exists = [&](const Cell& begin, const Cell& end, DIRECTION dir) {
            if (at(begin) == 0 || at(end) == 0) {
                return false;
            }

            // auto cur = begin;

            // while (cur != end) {
            //     cur = apply(cur, dir, 1);

            //     if (at(cur) == 0) return false;
            // }
            if (dir == DIRECTION::NEGATIVE_X) {
                return segment_exists(end, begin, DIRECTION::POSITIVE_X);
            }
            if (dir == DIRECTION::NEGATIVE_Y) {
                return segment_exists(end, begin, DIRECTION::POSITIVE_Y);
            }

            if (dir == DIRECTION::POSITIVE_X) {
                assert(begin.second == end.second);
                int total_sum = col_pref[end.first][end.second];

                if (begin.first != 0) {
                    total_sum -= col_pref[begin.first - 1][end.second];
                }

                return total_sum == (end.first - begin.first + 1);
            } else if (dir == DIRECTION::POSITIVE_Y) {
                assert(begin.first == end.first);
                int total_sum = row_pref[end.first][end.second];

                if (begin.second != 0) {
                    total_sum -= row_pref[begin.first][begin.second - 1];
                }

                return total_sum == (end.second - begin.second + 1);
            }

            return false;
        };


        int count = 0;

        FOR(i, n) {
            FOR(j, m) {
                Cell cur_cell = {i, j};

                for (auto dir : {DIRECTION::NEGATIVE_X, DIRECTION::POSITIVE_X, DIRECTION::NEGATIVE_Y, DIRECTION::POSITIVE_Y}) {
                    // We can binary search for this length.
                    int L = 2, R = max(n, m) + 1;

                    auto is_length_valid = [&](int length) {
                        int found = 0;

                        Cell intersection_cell = apply(cur_cell, dir, length - 1);

                        if (!valid(intersection_cell)) return found;

                        if (!segment_exists(cur_cell, intersection_cell, dir)) return found;

                        for (auto pdir : get_perpendicular_directions(dir)) {
                            auto end_cell = apply(intersection_cell, pdir, 2 * length - 1);

                            if (!valid(end_cell)) continue;

                            if (segment_exists(intersection_cell, end_cell, pdir)) {
                                ++found;
                            }
                        }

                        return found;
                    };

                    while (L < R) {
                        int m = L;

                        if (is_length_valid(m)) {
                            count += is_length_valid(m);
                            L = m + 1;
                        } else {
                            break;
                            // R = m;
                        }
                    }
                }
            }
        }

        cout << "Case #" << case_num << ": " << count << endl;
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}