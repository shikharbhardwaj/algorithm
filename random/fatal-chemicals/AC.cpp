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


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif
    int n, m, d, k;
    cin >> n >> m >> d >> k;

    string dangerous;
    cin >> dangerous;

    vector<array<bool, 26>> chemical_has_letter(n);

    for (auto& e : chemical_has_letter) {
        string chemical; cin >> chemical;

        for (auto pigment : chemical) {
            e[pigment - 'A'] = true;
        }
    }

    // Find the smallest subset of chemicals.
    int ans = d;

    for (int mask = 0; mask < (1 << d); ++mask) {
        int good_count = 0;

        for (int i = 0; i < n; ++i) {
            bool bad = false;

            for (int j = 0; j < d; ++j) {
                if (mask & (1 << j)) continue;

                int idx = dangerous[j] - 'A';

                if (chemical_has_letter[i][idx]) {
                    bad = true;
                    break;
                }
            }

            if (!bad) ++good_count;
        }

        if (good_count >= k) {
            ans = min(ans, __builtin_popcount(mask));
        }
    }

    cout << ans << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}