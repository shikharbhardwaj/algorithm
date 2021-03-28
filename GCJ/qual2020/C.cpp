#include <bits/stdc++.h>

// #define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)
#define CASE int C; std::cin >> C; FOR(case_num, C)
#define ALL(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using namespace std;


string solve(vector<pii>& ranges) {
    int n = ranges.size();
    vector<int> starts, ends;

    for (auto r : ranges) {
        starts.push_back(r.first);
        ends.push_back(r.second);
    }

    sort(begin(starts), end(starts));
    sort(begin(ends), end(ends));

    auto s_it = starts.begin();
    auto e_it = ends.begin();

    int max_cnt = 0, cur_cnt = 0;

    while (s_it != starts.end()) {
        if (*s_it < *e_it) {
            ++cur_cnt;
            max_cnt = max(max_cnt, cur_cnt);
            ++s_it;
        } else {
            --cur_cnt;
            ++e_it;
        }
    }

    if (max_cnt > 2) return "IMPOSSIBLE";

    vector<int> idx(ranges.size());

    iota(begin(idx), end(idx), 0);

    sort(begin(idx), end(idx), [&](int l, int r) {
        return ranges[l] < ranges[r];
    });

    vector<pair<int, char>> occupation = {{-1, 'C'}, {-1, 'J'}};

    string ans(n, ' ');

    for(auto i : idx) {
        for (auto& p : occupation) {
            if (p.first <= ranges[i].first) {
                ans[i] = p.second;
                p.first = ranges[i].second;
                break;
            }
        }
    }

    return ans;
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
    CASE {
        int n; cin >> n;
        vector<pii> ranges(n);

        for (auto& e: ranges) cin >> e.first >> e.second;

        cout << "Case #" << case_num + 1 << ": " << solve(ranges) << endl;
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}