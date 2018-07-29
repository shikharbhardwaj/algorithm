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
		int N, K, x;
		cin >> N;
		vector<double> ar(N);
		FOR(i, N) {
			cin >> x;
			ar[i] = log2(x);
		}

		cin >> K;
		// Try the prefix double approach.
		double target = log2(K), cur = 0;
		int i = 0, j = 0;
		int ans = 0;
		while(i < N) {
			while(j < N && cur < target) {
				cur += ar[j];
				ans += (j - i);
				++j;
			}
			cout << "Got : " << pii(i, j) << endl;
			while(i < j) {
				cur -= ar[i];
				++i;
			}
		}
		cout << ans << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
