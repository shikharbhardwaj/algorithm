#include <bits/stdc++.h>

#define ONLINE_JUDGE

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
        int N; cin >> N;
        int K; cin >> K;

        string s; cin >> s;

        int num_diff = 0;

        for (int i = 0, j = N - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                ++num_diff;
            }
        }

        cout << "Case #" << case_num << ": " << abs(num_diff - K) << endl;
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}