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

bool check(const string& str) {
    vector<char> stack;

    for (auto e : str) {
        switch(e) {
            case '(': stack.push_back(e); break;
            case ')': if (stack.empty()) return false;
            else stack.pop_back();
        }
    }

    return stack.empty();
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
    TEST {
        string in; cin >> in;
        // All possible assignments? 8
        // Some don't make sense at all.
        // {A, B, C} = {(, (, (}

        bool possible = false;

        for (int i = 0; i < 8; ++i) {
            char a = '(', b = '(', c = '(';
            if (i & 1) {
                a = ')';
            }
            if (i & 2) {
                b = ')';
            }
            if (i & 4) {
                c = ')';
            }

            auto modified_str = in;

            for (auto& e : modified_str) {
                switch(e) {
                    case 'A': e = a; break;
                    case 'B': e = b; break;
                    case 'C': e = c; break;
                }
            }

            possible = possible || check(modified_str);
        }

        cout << (possible ? "YES" : "NO") << endl;
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}