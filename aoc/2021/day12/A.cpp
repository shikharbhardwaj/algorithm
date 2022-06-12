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

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif     
    unordered_map<string, unordered_set<string>> graph;

    string line;
    while (cin >> line) {
        auto nodes = split(line, '-');
        graph[nodes[0]].insert(nodes[1]);
        graph[nodes[1]].insert(nodes[0]);
    }

    int ans = 0;

    function<void(string, vector<string>, set<string>, bool)> visit = [&](string node, vector<string> visited, set<string> seen, bool used) {
        if (node == "end") {
            // cout << visited << endl;
            ++ans; return;
        }

        visited.push_back(node);

        if (islower(node[0])) {
            seen.insert(node);
        }

        for (auto nei : graph[node]) {
            if (nei == "start") continue;

            if (seen.count(nei)) {
                if (!used) {
                    visit(nei, visited, seen, true);
                }
            } else {
                visit(nei, visited, seen, used);
            }
        }
    };

    visit("start", {}, {}, false);
    cout << ans << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}