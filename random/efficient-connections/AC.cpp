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
    int N, M, K;
    cin >> N >> M >> K;
 
    assert(N >= 1);
    assert(M >= 1);
    assert(K >= 1);
    assert((long long) K <= (long long) N * M);
 
    vector<int> A(N), B(M);
 
    for (auto& e : A) cin >> e;
    for (auto& e : B) cin >> e;
 
    sort(begin(A), end(A));
 
    using Entry = pair<int, int>;
    priority_queue<Entry, vector<Entry>, greater<Entry>> pqueue;
 
    for (auto e : B) {
        pqueue.emplace(A[0] + e, 0);
    }
 
    int ans = 0;
 
    while (K--) {
        auto [sum, idx] = pqueue.top();
        pqueue.pop();
        ans += sum;
 
        if (idx + 1 < N) {
            int next = A[idx + 1];
            int other = sum - A[idx];
            pqueue.emplace(next + other, idx + 1);
        }
    }
 
    cout << ans << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}
