#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
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

void solve_part1() {
    string line;

    int cur_cycle = 1, value = 1;

    int ans = 0;

    auto is_special_cycle = [](int cur_cycle) {
        return (cur_cycle - 20) % 40 == 0;
    };

    auto noop = [&]() {
        if (is_special_cycle(cur_cycle)) {
            ans += cur_cycle * value;
        }
        cur_cycle++;
    };

    auto addx = [&](int x) {
        // This addx can affect the strength only when we start with the special
        // cycle.
        if (is_special_cycle(cur_cycle)) {
            ans += cur_cycle * value;
        }
        cur_cycle += 1;
        if (is_special_cycle(cur_cycle)) {
            ans += cur_cycle * value;
        }
        cur_cycle += 1;
        value += x;
    };

    while (getline(cin, line)) {
        auto tokens = split(line);
        string opcode = tokens[0];

        switch (opcode[0]) {
            case 'a': addx(stoi(tokens[1])); break;
            case 'n': noop();
        }
    }

    cout << ans << endl;
}

void solve_part2() {
    string line;

    const int height = 6, width = 40;

    vector<string> screen(height, string(width, '.'));

    int cur_cycle = 1, value = 1;

    int ans = 0;

    auto get_cur_pos = [](int cycle_idx) {
        int row = (cycle_idx / width) % height;
        int col = cycle_idx % width;

        return make_pair(row, col);
    };

    auto draw_pixel = [&]() {
        auto [r, c] = get_cur_pos(cur_cycle - 1);

        if (abs(c - value) <= 1) {
            screen[r][c] = '#';
        }
    };

    auto noop = [&]() {
        draw_pixel();
        cur_cycle+=1;
    };

    auto addx = [&](int x) {
        // This addx can affect the strength only when we start with the special
        // cycle.
        draw_pixel();
        cur_cycle += 1;
        draw_pixel();
        cur_cycle += 1;
        value += x;
    };

    while (getline(cin, line)) {
        auto tokens = split(line);
        string opcode = tokens[0];

        switch (opcode[0]) {
            case 'a': addx(stoi(tokens[1])); break;
            case 'n': noop();
        }
    }

    for (auto row : screen) {
        cout << row << endl;
    }
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
    // solve_part1();
    solve_part2();
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}