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
    const int MAX_BIT_COUNT = 20;
    vector<int> set_count(MAX_BIT_COUNT);


    int bit_count = MAX_BIT_COUNT;

    int n = 0;
    string input;
    while (cin >> input) {
        bit_count = input.size();

        for (int i = 0; i < input.size(); ++i) {
            set_count[i] += input[i] - '0';
        }
        ++n;
    }

    cout << set_count << endl;
    cout << bit_count << endl;

    int gamma = 0, epsilon = 0;
    int base = 1;

    for (int i = bit_count; i-- > 0 ;) {
        if (set_count[i] > n / 2) {
            gamma += base;
        } else {
            epsilon += base;
        }
        base *= 2;
    }

    cout << gamma * epsilon << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}