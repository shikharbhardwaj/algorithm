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


/*
For each letter,
    find the shortest path to transform to another letter.
    BFS?
*/

map<pair<char, char>, int> get_min_cost_map(const vector<pair<char, char>>& edges) {
    map<char, unordered_set<char>> graph;

    map<pair<char, char>, int> cost;

    for (auto [u, v] : edges) {
        graph[u].insert(v);
    }

    auto bfs = [&](char src) {
        vector<char> frontier = {src}, next;
        vector<bool> visited(255);

        visited[src] = true;
        
        int dist = 0;

        while (!frontier.empty()) {
            auto u = frontier.back(); frontier.pop_back();

            cost[{src, u}] = dist;

            for (auto v : graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    next.push_back(v);
                }
            }

            if (frontier.empty()) {
                frontier = move(next);
                next.clear();
                ++dist;
            }
        }
    };

    for (int i = 'A'; i <= 'Z'; ++i) {
        bfs(i);
    }

    return cost;
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
    int N; cin >> N;

    for (size_t case_num = 1; case_num <= N; case_num++) {
        string S; cin >> S;
        int K; cin >> K;

        vector<pair<char, char>> edges(K);

        for (auto& e : edges) {
            string x; cin >> x;
            e.first = x[0];
            e.second = x[1];
        }

        auto cost_map = get_min_cost_map(edges);

        int ans = -1;

        for (char a = 'A'; a <= 'Z'; ++a) {
            int cur = 0;
            bool valid = true;

            for (int i = 0; i < S.size(); ++i) {
                if (S[i] == a) continue;

                if (cost_map.count({S[i], a})) {
                    cur += cost_map[{S[i], a}];
                } else {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                if (ans == -1) ans = cur;
                else ans = min(ans, cur);
            }
        }

        cout << "Case #" << case_num << ": " << ans << endl;
    }
    
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}