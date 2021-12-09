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


vector<string> split(string str, char delim) {
    istringstream ss(str);

    string token;
    vector<string> toknes;

    while (getline(ss, token, delim)) {
        toknes.push_back(token);
    }

    return toknes;
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
    string line; cin >> line;

    vector<string> input = split(line, ',');
    vector<int> nums;

    for (auto e : input) nums.push_back(stoi(e));

    auto sum = accumulate(begin(nums), end(nums), 0);
    int n = nums.size();

    sort(begin(nums), end(nums));

    cout << nums << endl;

    int pref = 0, suff = sum, best = INT_MAX;

    for (int i = 0; i < nums.size();) {
        int cur = nums[i];
        int x = 0, cnt = 0, prev = i;

        while (i < nums.size() && nums[i] == cur) {
            x += nums[i];
            ++i; ++cnt;
        }

        suff -= x;

        int pref_cost = cur * prev - pref;
        int suf_cost = suff - cur * (n - i);

        // cout << i << "(" << n - i << ")"<< " :: " << pref_cost << ", " << suf_cost << endl;

        best = min(best, pref_cost + suf_cost);
        pref += x;
    }

    cout << n << endl;

    cout << best << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}