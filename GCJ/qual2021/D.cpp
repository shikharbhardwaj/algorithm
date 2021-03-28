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
    int T, N, Q; cin >> T >> N >> Q;

    FOR (t, T) {
        int query_cnt = 0;
        vector<int> discovered;

        auto query = [&](const vector<int>& xs) {
            ++query_cnt;
            copy(begin(xs), end(xs), ostream_iterator<int>(cout, " "));
            cout << endl;
            int x; cin >> x;

            return x;
        };

        // Initialize with the first query.
        int m = query({1, 2, 3});

        int nxt = 4;

        switch (m) {
            case 1: discovered = {2, 1, 3}; break;
            case 2: discovered = {1, 2, 3}; break;
            case 3: discovered = {1, 3, 2}; break;
        }

        while (query_cnt < Q && discovered.size() < N) {
            // cerr << "Discovered: ";
            // copy(begin(discovered), end(discovered), ostream_iterator<int>(cerr, " "));
            // cerr << endl;
            // cerr << "nxt: " << nxt << endl;

            bool found = false;

            // Check if it can be inserted at the ends.
            int q_end = query({discovered[0], discovered.back(), nxt});
            if (q_end != nxt) {
                if (q_end == discovered[0]) {
                    discovered.insert(begin(discovered), nxt);
                } else {
                    discovered.push_back(nxt);
                }
                found = true;
            }

            if (!found) {
                int L = 1, R = discovered.size() - 1;

                while (R - L > 2) {
                    int m = L + (R - L) / 2;

                    int q = query({discovered[L], nxt, discovered[m]});

                    if (q == discovered[m]) {
                        L = m + 1;
                    } else {
                        R = m;
                    }
                }

                // cerr << "Ended at: " << L << ", "  << R << endl;

                for (auto i = L; i <= R; ++i) {
                    if (found) break;

                    int q = query({discovered[i - 1], nxt, discovered[i]});
                    if (q == nxt) {
                        discovered.insert(begin(discovered) + i, nxt);
                        found = true;
                    }
                }
            }

            // Randomize ordering.

            ++nxt;
            // copy(begin(discovered), end(discovered), ostream_iterator<int>(cerr, " "));
            // cerr << endl;
        }

        copy(begin(discovered), end(discovered), ostream_iterator<int>(cout, " "));
        cout << endl;

        cerr << "Queries: " << query_cnt << endl;

        int verdict; cin >> verdict;

        if (verdict != 1) {
            break;
        }
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}