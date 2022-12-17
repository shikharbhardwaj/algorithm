#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <sstream>
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

vector<string> split(const string& str, char delim=' ') {
    istringstream ss(str);
    string token;
    vector<string> tokens;

    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
}

struct Point {
    int x, y;

    Point(int x_, int y_) : x(x_), y(y_) {}
};

ostream& operator<<(ostream& os, const Point& p) {
    return os << "Point(x=" << p.x << ", " << p.y << ")";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in2.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif
    string line;
    constexpr int length = 1000, height = 1000;
    vector<string> grid(height, string(length, '.'));

    auto showGrid = [&](const Point& start, const Point& end) {
        for (int i = start.y; i <= end.y; ++i) {
            for (int j = start.x; j <= end.x; ++j) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    };

    auto drawLine = [&](const Point& start, const Point& end) {
        if (start.x == end.x) {
            for (int i = min(start.y, end.y); i <= max(start.y, end.y); ++i) {
                grid[i][start.x] = '#';
            }
        } else if (start.y == end.y) {
            for (int j = min(start.x, end.x); j <= max(start.x, end.x); ++j) {
                grid[start.y][j] = '#';
            }
        }
    };

    int max_y = 0;

    while (getline(cin, line)) {
        auto tokens = split(line);

        vector<Point> points;

        for (int i = 0; 2 * i < tokens.size(); ++i) {
            auto coords = split(tokens[2 * i], ',');
            points.emplace_back(stoi(coords[0]), stoi(coords[1]));
            max_y = max(max_y, points.back().y);
        }

        for (int i = 1; i < points.size(); ++i) {
            drawLine(points[i - 1], points[i]);
        }
    }

    max_y = max_y + 1;

    auto down = [](const Point& pos) -> Point {
        return {pos.x, pos.y + 1};
    };
    auto left = [](const Point& pos) -> Point {
        return {pos.x - 1, pos.y + 1};
    };
    auto right = [](const Point& pos) -> Point {
        return {pos.x + 1, pos.y + 1};
    };

    auto set = [&](const Point &pos, char val) {
        grid[pos.y][pos.x] = val;
    };

    auto get = [&](const Point& pos) -> char {
        return grid[pos.y][pos.x];
    };

    function<Point(const Point&)> move_sand = [&](const Point& pos) -> Point {
        // cout << pos << endl;
        // showGrid({494, 0}, {503, 9});
        if (pos.y == max_y) return pos;

        if (get(down(pos)) == '.') {
            set(pos, '.');
            set(down(pos), 'o');
            return move_sand(down(pos));
        } else if (get(left(pos)) == '.') {
            set(pos, '.');
            set(left(pos), 'o');
            return move_sand(left(pos));
        } else if (get(right(pos)) == '.') {
            set(pos, '.');
            set(right(pos), 'o');
            return move_sand(right(pos));
        }

        return pos;
    };

    int num_units_done = 0;
    while (true) {
        grid[0][500] = 'o';
        auto final_pos = move_sand({500, 0});

        if (final_pos.y == 0 && final_pos.x == 500) break;

        ++num_units_done;
    }

    showGrid({488, 0}, {513, 11});

    cout << num_units_done << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}