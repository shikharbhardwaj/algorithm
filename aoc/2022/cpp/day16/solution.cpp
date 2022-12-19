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
    ifstream fin("in2.txt");
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

    vector<string> nodes;
    for (auto [node, _] : graph) {
        nodes.push_back(node);
    }
    sort(ALL(nodes));
    vector<int> flow_rate_by_idx(nodes.size());
    for (int i = 0; i < nodes.size(); ++i) {
        flow_rate_by_idx[i] = flow_rate[nodes[i]];
    }

    cout << nodes << endl;
    cout << flow_rate_by_idx << endl;

    using State = tuple<int, int, ull, int, ull>;
    map<State, int> dp;

    ull progress_counter = 0;
    ull progress_batch = 1e6;

    /*
    Cases:
    1. Elephant and me on the same node: elephant moves onto the neighbour, and I try to see if
    turning on the current valve is useful.
    2. Elephant and me on different nodes: both explore with/without turning on the current valve.
    */

    function<ull(int, int, ull, int, ull)> visit = [&](int node0_idx, int node1_idx, ull cur, int t, ull bits) -> ull {
        if (t <= 0) return cur;
        
        auto cur_state = make_tuple(node0_idx, node1_idx, cur, t, bits);
        // cout << cur_state << endl;

        if (dp.count(cur_state) != 0) {
            // cout << "Found existing state" << endl;
            return dp[cur_state];
        }
        ++progress_counter;

        if (progress_counter % progress_batch == 0) {
            cout << "Visited: " << progress_counter << endl;
        }

        // cout << "Visit: " << cur_state << endl;
        ull best = cur;

       string node0 = nodes[node0_idx];
       string node1 = nodes[node1_idx];

        for (auto nei0 : graph[node0]) {
            int nei0_idx = lower_bound(ALL(nodes), nei0) - begin(nodes);
            best = max(best, visit(nei0_idx, node1_idx, cur, t - 1, bits));
        }

        if (!(bits & (1 << node0_idx)) && flow_rate_by_idx[node0_idx] > 0) {
            cur += (t - 1) * flow_rate[node0];

            bits |= (1 << node0_idx);

            for (auto nei0 : graph[node0]) {
                int nei0_idx = lower_bound(ALL(nodes), nei0) - begin(nodes);
                best = max(best, visit(nei0_idx, node1_idx, cur, t - 2, bits));
            }
        }

        return dp[cur_state] = best;
    };

    cout << graph << endl;
    cout << flow_rate << endl;
    cout << visit(0, 0, 0, 30, 0) << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}