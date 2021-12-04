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
    string token;
    vector<string> tokens;

    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
}

const int BOARD_SIZE = 5;

using Board = array<array<string, BOARD_SIZE>, BOARD_SIZE>;

class BingoBoard {
    unordered_map<string, vector<pair<int, int>>> value_idx;
    array<int, BOARD_SIZE> row_count{}, col_count{};

public:
    BingoBoard(const Board& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                value_idx[board[i][j]].emplace_back(i, j);
            }
        }
    }

    void mark_number(string num) {
        if (value_idx.count(num) == 0) return;

        for (auto [i, j] : value_idx.at(num)) {
            ++row_count[i];
            ++col_count[j];
        }

        value_idx.erase(num);
    }

    bool is_won() {
        return any_of(begin(row_count), end(row_count), [](int cnt) {
            return cnt == BOARD_SIZE;
        }) || any_of(begin(col_count), end(col_count), [](int cnt) {
            return cnt == BOARD_SIZE;
        });
    }

    int sum() {
        return accumulate(begin(value_idx), end(value_idx), 0, [](int s, const pair<string, vector<pair<int, int>>>& p) {
            return s + stoi(p.first) * p.second.size();
        });
    }
};

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif     
    string numbers_input; cin >> numbers_input;
    vector<string> numbers = split(numbers_input, ',');

    int best_iters = 0, score;

    bool done = false;

    while (!done) {
        Board board;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                string elem;
                if (!(cin >> elem)) break;
                board[i][j] = elem;
            }
        }

        if (!cin) {
            done = true;
            break;
        }

        int seen = 0;
        BingoBoard bingo(board);

        auto next = [&]() {
            auto cur = numbers[seen];
            bingo.mark_number(cur);

            return !bingo.is_won();
        };

        while (seen < numbers.size() && next()) ++seen;

        if (best_iters < seen) {
            best_iters = seen;
            int last = stoi(numbers[seen]);
            int sum = bingo.sum();
            score = sum * last;
        }
    }

    cout << score  << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}