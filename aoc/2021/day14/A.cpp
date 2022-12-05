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

#define ONLINE_JUDGE

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

vector<string> split(const string& input, char delim = ' ') {
    istringstream ss(input);

    vector<string> tokens;
    string token;

    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
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
    string current_polymer;
    cin >> current_polymer;

    cout << current_polymer << endl;

    string line;

    map<pair<char, char>, char> mapping;

    while (getline(cin, line)) {
        if (line.empty()) continue;

        auto tokens = split(line);
        auto polyer_pair = tokens[0];
        mapping[make_pair(polyer_pair[0], polyer_pair[1])] = tokens[2][0];
    }

    cout << mapping << endl;

    map<pair<char, char>, ull> pair_counts;

    for (int i = 1; i < current_polymer.size(); ++i) {
        pair_counts[make_pair(current_polymer[i - 1], current_polymer[i])]++;
    }

    int step_cnt = 40;

    auto apply = [&]() {
        map<pair<char, char>, ull> next_pair_counts;

        for (char first = 'A'; first <= 'Z'; ++first) {
            for (char second = 'A'; second <= 'Z'; ++second) {
                auto cur_pair = make_pair(first, second);

                if (!pair_counts.count(cur_pair)) {
                    continue;
                }

                auto existing = pair_counts[cur_pair];

                if (mapping.count(cur_pair)) {
                    auto mid = mapping[cur_pair];
                    next_pair_counts[make_pair(first, mid)] += existing;
                    next_pair_counts[make_pair(mid, second)] += existing;
                } else {
                    next_pair_counts[cur_pair] = existing;
                }
            }
        }

        pair_counts = next_pair_counts;
    };

    while (step_cnt--) {
        apply();
    }

    map<char, ull> freq;

    ull mn = 1e18, mx = 0;

    cout << pair_counts << endl;

    for (auto [pair, cnt] : pair_counts) {
        auto [first, second] = pair;
        freq[first] += cnt;
        freq[second] += cnt;
    }

    for (auto [_, v] : freq) {
        mn = min(mn, v);
        mx = max(mx, v);
    }

    cout << mx << endl;
    cout << mn << endl;

    cout << (mx / 2) - (mn / 2) + 1 << endl;

#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}