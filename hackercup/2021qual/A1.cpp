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

bool is_vowel(char ch) {
    switch (ch) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
    }

    return false;
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
    int N; cin >> N;

    for (int case_num = 1; case_num <= N; ++case_num) {
        string S; cin >> S;

        int cost = 2 * S.size();

        for (char a = 'A'; a <= 'Z'; ++a) {
            int cur = 0;

            for (int i = 0; i < S.size(); ++i) {
                if (S[i] == a) continue;

                if (is_vowel(S[i]) ^ is_vowel(a)) cur += 1;
                else cur += 2;
            }

            cost = min(cost, cur);
            // cout << "Cost: " << cost << " " << a << endl;
        }

        cout << "Case #" << case_num << ": " << cost << endl;
    }

#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}