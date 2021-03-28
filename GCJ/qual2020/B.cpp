#include <bits/stdc++.h>

#define ONLINE_JUDGE

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


std::string solve(const std::string& in) {
    int cur_cnt = 0;
    std::string ans;

    for (auto e : in) {
        int d = e - '0';

        while (cur_cnt < d) {
            ans += "(";
            ++cur_cnt;
        }

        while (cur_cnt > d) {
            ans += ")";
            --cur_cnt;
        }

        ans += e;
    }

    while(cur_cnt--) {
        ans += ")";
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
        std::string input; cin >> input;
        std::cout << "Case #" << case_num + 1 << ": " << solve(input) << endl;
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}