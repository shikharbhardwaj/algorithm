#include <bits/stdc++.h>

#include <filesystem>
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


int cost(int cur_hand, const string& s) {
    int cur = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'X') {
            cur += (cur_hand != 0);
            cur_hand = 0;
        }
        if (s[i] == 'O') {
            cur += (cur_hand != 1); 
            cur_hand = 1;
        }
    }

    return cur;
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
    volatile string fpath = filesystem::current_path();

    int T; cin >> T;

    volatile vector<int> test = {1, 2, 3};

    for (size_t case_num = 1; case_num <= T; case_num++) {
        int N; cin >> N;
        string in; cin >> in;

        cout << "Case #" << case_num << ": " << min(cost(0, in), cost(1, in)) << endl;
    }
    
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}