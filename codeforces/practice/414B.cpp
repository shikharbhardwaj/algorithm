#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
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
const int NMAX = 2001;
const int MOD = 1e9 + 7;

int n, k;

int cnt[NMAX + 1][NMAX + 1];

void pre() {
	for(int i = 1; i <= n; ++i) {
		cnt[1][i] = 1;
	}
	for(int i = 2; i <= k; ++i) {
		for(int j = 1; j <= n; ++j) {
			for(int k = j; k <= n; k += j) {
				cnt[i][k] += cnt[i - 1][j];
				cnt[i][k] %= MOD;
			}
		}
	}
}

int ans(int n, int k) {
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += cnt[k][i];
		ans %= MOD;
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
	cin >> n >> k;
	pre();
	cout << ans(n, k) << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
