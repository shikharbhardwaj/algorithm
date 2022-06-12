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


void solve(const vector<int>& nums) {
    const int n = nums.size();
    vector<int> even, odd;

    for (int i = 0; i < n; ++i) {
        if (nums[i] % 2) odd.push_back(i);
        else even.push_back(i);
    }

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; ++i) {
        int left = i - nums[i], right = i + nums[i];
        if (right < n) graph[right].emplace_back(i);
        if (left >= 0) graph[left].emplace_back(i);
    }

    vector<int> ans(n, -1);

    auto bfs = [&](vector<int>& start, vector<int>& end) {
        queue<int> q;
        vector<int> dist(n, n + 2);

        for (auto e : start) {
            dist[e] = 0;
            q.push(e);
        }

        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            for (auto v : graph[u]) {
                if (dist[v] == n + 2) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        for (auto e : end) {
            if (dist[e] != n + 2) ans[e] = dist[e];
        }
    };

    bfs(odd, even);
    bfs(even, odd);

    for (auto e : ans) {
        cout << e << " ";
    }
    cout << endl;
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
    int n; cin >> n;
    vector<int> nums(n);

    for (auto& e : nums) {
        cin >> e;
    }

    solve(nums);
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}