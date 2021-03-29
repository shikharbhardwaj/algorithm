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


int min_limit(int n) {
    return n - 1;
}

int max_limit(int n) {
    return n * (n + 1) / 2 - 1;
}

bool possible(int n, int c) {
    return c >= min_limit(n) && c <= max_limit(n);
}

bool pref_possible(int pref, int n, int c) {
    return pref <= c && c <= pref * (2 * n - pref + 1) / 2;
}

vector<int> solve(int n, int c) {
    vector<int> ans(n);
    iota(begin(ans), end(ans), 1);

    for (int i = n - 2; i >= 0; --i) {
        for (int len = 1; len <= n - i; ++len) {
            if (pref_possible(i, n, c - len)) {
                reverse(begin(ans) + i, begin(ans) + i + len);
                c -= len;
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
        int N, C; cin >> N >> C;

        if (possible(N, C)) {
            cout << "Case #" << case_num << ": ";
            for (auto e : solve(N, C)) {
                cout << e << " ";
            }

            cout << endl;
        } else {
            cout << "Case #" << case_num << ": IMPOSSIBLE" << endl;
        }
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}