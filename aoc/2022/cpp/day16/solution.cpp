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
        if (token.empty()) continue;
        tokens.push_back(token);
    }

    return tokens;
}

int parse_coordinate(string coordinate_str) {
    auto start_it = next(find(begin(coordinate_str), end(coordinate_str), '='));
    auto end_it = find_if(start_it, end(coordinate_str), [](char ch) { return ch == ':' || ch == ','; });
    auto num = string{ start_it, end_it };
    return stoi(num);
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
    map<string, vector<string>> graph;
    map<string, int> flow_rate;

    while (getline(cin, line)) {
        auto tokens = split(line);
        auto node = tokens[1];

        int valve_flow_rate = parse_coordinate(tokens[4]);
        flow_rate[node] = valve_flow_rate;

        for (int i = 9; i < tokens.size(); ++i) {
            if (tokens[i].back() == ',') tokens[i].pop_back();

            graph[node].push_back(tokens[i]);
        }
    }

    int max = 0;
    set<string> visited;

    auto max = [&](const string& node, int cur, int t, string parent, map<string, bool> valve_state) {
        // We always turn on the current valve if it has > 0 value.
        if (flow_rate[node] > 0) {
            t -= 1;
            // cur += flow_rate * ;
        }
    };

    cout << graph << endl;
    cout << flow_rate << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}