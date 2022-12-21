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

    using Result = int;
    using State = tuple<int, int, ull, int>;
    map<State, Result> dp;

    ull progress_counter = 0;
    ull progress_batch = 1e6;

    const int max_time = 26;

    function<Result(int, int, ull, int)> visit = [&](int node0_idx, int t, ull bits, int num_players) -> Result {
        if (t == 0) {
            return num_players > 0 ? visit(0, max_time, bits, num_players-1) : 0;
        }
        
        auto cur_state = make_tuple(node0_idx, t, bits, num_players);
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
        Result best = 0;

        string node0 = nodes[node0_idx];

        if (!(bits & (1ull << node0_idx)) && flow_rate_by_idx[node0_idx] > 0) {
            auto next_bits = bits | (1ull << node0_idx);
            best = max(best, (t - 1) * flow_rate_by_idx[node0_idx] + visit(node0_idx, t - 1, next_bits, num_players));
        }

        for (auto nei0 : graph[node0]) {
            int nei0_idx = lower_bound(ALL(nodes), nei0) - begin(nodes);
            best = max(best, visit(nei0_idx, t - 1, bits, num_players));
        }

        // while (t--) {
        //     best = max(best, visit(node0_idx, cur, t, bits, num_players));
        // }

        return dp[cur_state] = best;
    };

    auto first_pass_result = visit(0, max_time, 0, 1);
    cout << first_pass_result << endl;

#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}