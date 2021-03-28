#include <bits/stdc++.h>

// #define ONLINE_JUDGE

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)
#define ALL(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>#include <bits/stdc++.h>

// #define ONLINE_JUDGE

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin(INPUT_FILE);
    ofstream fout(OUTPUT_FILE);
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
    int cases; cin >> cases;

    FOR (c, cases) {
        int n; cin >> n;

        vector<vi> mat(n, vi(n));

        FOR(i, n) {
            FOR(j, n) {
                cin >> mat[i][j];
            }
        }

        int trace = 0, col_repeat = 0, row_repeat = 0;

        FOR (i, n) {
            trace += mat[i][i];
        }

        FOR(i, n) {
            vector<bool> seen(n + 1, false);

            FOR(j, n) {
                seen[mat[i][j]] = true;
            }

            row_repeat += (count(begin(seen), end(seen), true) != n);
        }
 
        FOR(j, n) {
            vector<bool> seen(n + 1, false);

            FOR(i, n) {
                seen[mat[i][j]] = true;
            }

            col_repeat += (count(begin(seen), end(seen), true) != n);
        }

        cout << "Case #" << c + 1 << ": " << trace << " " << row_repeat << " " << col_repeat << endl;
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}
;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin(INPUT_FILE);
    ofstream fout(OUTPUT_FILE);
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
    int cases; cin >> cases;

    FOR (c, cases) {
        int n; cin >> n;

        vector<vi> mat(n, vi(n));

        FOR(i, n) {
            FOR(j, n) {
                cin >> mat[i][j];
            }
        }

        int trace = 0, col_repeat = 0, row_repeat = 0;

        FOR (i, n) {
            trace += mat[i][i];
        }

        FOR(i, n) {
            vector<bool> seen(n + 1, false);

            FOR(j, n) {
                seen[mat[i][j]] = true;
            }

            row_repeat += (count(begin(seen), end(seen), true) != n);
        }
 
        FOR(j, n) {
            vector<bool> seen(n + 1, false);

            FOR(i, n) {
                seen[mat[i][j]] = true;
            }

            col_repeat += (count(begin(seen), end(seen), true) != n);
        }

        cout << "Case #" << c << ": " << trace << " " << row_repeat << " " << col_repeat << endl;
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}
