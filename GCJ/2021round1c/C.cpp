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

int bitwise_not(int x) {
    bitset<32> bs(x);
    bs.flip();

    // Ignore all bits which appeared after msb.
    int leading_zeros = __builtin_clz(x);

    for (int i = 0; i < leading_zeros; ++i) bs.reset(i);

    return bs.to_ulong();
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
        string S, E;

        cin >> S >> E;

        int s = stoi(S, 0, 2), e = stoi(E, 0, 2);

        int ans = -1;

        function<void(int, int)> visit = [&](int x, int d = 0) {
            if (x == e) {
                if (ans == -1) ans = d;
                else ans = min(ans, d);
                return;
            }

            visit(2 * x, d + 1);
            visit(bitwise_not(x), d + 1);
        };

        visit(s, 0);

        cout << "Case #" << case_num << ": " << (ans) << endl;
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}

/*

0
1
10
100
011
110


*/