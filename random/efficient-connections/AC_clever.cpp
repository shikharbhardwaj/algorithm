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

int MAX_VAL = 1001;
 
int solve(vector<int>& nums0, vector<int>& nums1, int k) {
    vector<int> counts_a(MAX_VAL), counts_b(MAX_VAL);

    for (auto e : nums0) ++counts_a[e];
    for (auto e : nums1) ++counts_b[e];

    map<int, int> candidates;

    for (int i = 1; i < counts_a.size(); ++i) {
        for (int j = 1; j < counts_b.size(); ++j) {
            if (counts_a[i] != 0 && counts_b[j] != 0) {
                candidates[i + j] += counts_a[i] * counts_b[j];

                if (candidates.size() > k) {
                    candidates.erase(prev(candidates.end()));
                }
            }
        }
    }

    int cnt = 0, ans = 0;
    auto it = candidates.begin();

    while (cnt < k) {
        int cur = min(k - cnt, it->second);
        ans += cur * it->first;
        cnt += cur;
        ++it;
    }

    return ans;
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
    int N, M, K;
    cin >> N >> M >> K;
 
    assert(N >= 1);
    assert(M >= 1);
    assert(K >= 1);
    assert((long long) K <= (long long) N * M);
 
    vector<int> A(N), B(M);
 
    for (auto& e : A) cin >> e;
    for (auto& e : B) cin >> e;
 
 
    cout << solve(A, B, K) << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}
