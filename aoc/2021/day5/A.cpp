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

pair<pair<int, int>, pair<int, int>> parseLine(const string& line) {
    auto tokens = split(line, ' ');
    auto firstPair = split(tokens[0], ','), secondPair = split(tokens[2], ',');

    return make_pair(make_pair(stoi(firstPair[0]), stoi(firstPair[1])), make_pair(stoi(secondPair[0]), stoi(secondPair[1])));
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
    const int MAX_X = 1000, MAX_Y = 1000;

    array<array<int, MAX_X>, MAX_Y> board{};

    int cnt = 0;

    string line;
    while (getline(cin, line)) {
        auto [p0, p1] = parseLine(line);

        if (p0 > p1) swap(p0, p1);

        auto [x0, y0] = p0;
        auto [x1, y1] = p1;

        if (x0 == x1) {
            if (y0 > y1) swap(y0, y1);

            for (int i = y0; i <= y1; ++i) {
                board[x0][i]++;

                if (board[x0][i] == 2) ++cnt;
            }
        } else if(y0 == y1) {
            if (x0 > x1) swap(x0, x1);

            for (int i = x0; i <= x1; ++i) {
                board[i][y0]++;

                if (board[i][y0] == 2) ++cnt;
            }
        } else {
            int dx = (p0.first > p1.first) ? -1 : 1;
            int dy = (p0.second > p1.second) ? -1 : 1;

            // cout << p0 << ", " << p1 << endl;
            // cout << dx << ", " << dy << endl;

            while (p0 != p1) {
                auto [x, y] = p0;
                board[x][y]++;

                if (board[x][y] == 2) ++cnt;

                p0.first += dx;
                p0.second += dy;
            }

            board[p0.first][p0.second]++;

            if (board[p0.first][p0.second] == 2) ++cnt;
        }
    }

    // for (auto row : board) {
    //     cout << row << endl;
    // }

    // cout << board << endl;

    cout << cnt << endl;

#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}

/*

(561, 579),
(965, 175)

*/