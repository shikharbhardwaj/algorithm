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
		int N;
		cin >> N;
		vi ar(N);
		cin >> ar[0];
		int lowest = ar[0], mark = 0;
		FOR(i, N - 1) {
			cin >> ar[i + 1];
			lowest = min(lowest, ar[i + 1]);
			if(lowest == ar[i + 1])
				mark = i + 1;
		}
		// Rotate at the mark.
		std::rotate(ar.begin(), ar.begin() + mark, ar.end());
		// cout << ar << endl;
		int x;
		cin >> x;
		int idx = std::lower_bound(ALL(ar), x) - ar.begin();
		if(idx != N && ar[idx] == x) {
			cout << (idx + mark) % N << endl;
		} else {
			cout << "-1" << endl;
		}
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
