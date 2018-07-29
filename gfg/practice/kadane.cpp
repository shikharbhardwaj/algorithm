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

int max_contiguous(const vi &ar) {
	if(ar.size() == 0) return 0;

	int max_ending_here, max_so_far;
	max_ending_here = max_so_far = ar[0];

	for(int i = 1; i < ar.size(); ++i) {
		max_ending_here = max(max_ending_here + ar[i], ar[i]);
		max_so_far = max(max_so_far, max_ending_here);
	}
	return max_so_far;
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
	TEST {
		int N;
		cin >> N;
		vi ar(N);
		FOR(i, N) {
			cin >> ar[i];
		}
		cout << max_contiguous(ar) << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
