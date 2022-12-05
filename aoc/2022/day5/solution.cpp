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

vector<string> split(string input, char delim=' ') {
    istringstream ss(input);

    vector<string> tokens;
    string token;

    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
}

vector<string> parseLine(string line) {
    vector<string> crates;

    if ((line.size() + 1) % 4) {
        throw std::invalid_argument("Cannot parse line with size non-multiple of 4.");
    }
    int num_crates = (line.size() + 1) / 4;

    int crate_idx = 1;
    for (int i = 0; i < num_crates; ++i) {
        if (line[crate_idx] != ' ') {
            crates.push_back(string(1, line[crate_idx]));
        } else {
            crates.emplace_back();
        }
        crate_idx += 4;
    }

    cout << crates << endl;

    return crates;
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
    string line;
    vector<vector<char>> arrangement;
    int line_cnt = 0;
    while (getline(cin, line) && !line.empty()) {
        vector<string> crates = parseLine(line);

        arrangement.resize(crates.size());
        for (int i = 0; i < crates.size(); ++i) {
            if (!crates[i].empty()) {
                arrangement[i].push_back(crates[i][0]);
            }
        }
        ++line_cnt;
    }

    for (auto& e : arrangement) {
        reverse(ALL(e));
    }

    cout << arrangement << endl;

    while (getline(cin, line)) {
        auto tokens = split(line);
        int count = stoi(tokens[1]);
        int from = stoi(tokens[3]) - 1;
        int to = stoi(tokens[5]) - 1;

        vector<char> to_move;

        while (count--) {
            auto moved = arrangement[from].back();
            arrangement[from].pop_back();
            to_move.push_back(moved);
        }

        while (!to_move.empty()) {
            arrangement[to].push_back(to_move.back());
            to_move.pop_back();
        }
    }

    for (auto e : arrangement) {
        cout << e.back();
    }
    cout << endl;

#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}