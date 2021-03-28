#include <bits/stdc++.h>

#define ONLINE_JUDGE

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
        int X, Y; cin >> X >> Y;

        string in; cin >> in;

        unordered_map<string, int> pair_cost = {
            {"CJ", X},
            {"CC", 0},
            {"JC", Y},
            {"JJ", 0},
        };

        // lstrip ?, rstrip ?
        auto left_start = find_if(begin(in), end(in), [](char ch) {
            return ch != '?';
        });
        auto right_start = find_if(rbegin(in), rend(in), [](char ch) {
            return ch != '?';
        }).base();

        int cost = 0;

        string str = "C";

        if (distance(left_start, right_start) > 0) {
            str = string(left_start, right_start);
        }

        char prev_char = str[0];

        for (int i = 1; i < str.size(); ++i) {
            if (str[i] == '?') {
                auto next_it = find_if(begin(str) + i, end(str), [](char ch1) {
                    return ch1 != '?';
                });

                auto next_char = *next_it;

                cost += pair_cost[string(1, prev_char) + next_char];
                prev_char = next_char;
                i = next_it - begin(str);
            } else {
                cost += pair_cost[string(1, prev_char) + str[i]];
                prev_char = str[i];
            }
        }

        cout << "Case #" << case_num << ": " << cost << endl;
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}