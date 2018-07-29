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

int lbound(int i, int j, int x, const vi& ar) {
	int first = i;
	int cnt = j - i;
	while(cnt > 0) {
		int cur = i + cnt;
	}
	return first;
}

int find_pivot(int i, int j, const vi& ar) {
	if(j - i <= 1)
		return i;

	int mid = i + (j - i) / 2;

	if(ar[mid] > ar[mid + 1])
		return mid;

	if(ar[mid] < ar[i])
		return find_pivot(i, mid, ar);
	else
		return find_pivot(mid + 1, j, ar);
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
		int N, x;
		cin >> N;
		vi ar(N);
		FOR(i, N) {
			cin >> ar[i];
		}
		cin >> x;
		int mark = find_pivot(0, N, ar) + 1;
		int idx1 = lower_bound(ar.begin(), ar.begin() + mark, x) - ar.begin();
		if(ar[idx1] == x) {
			cout << idx1 << endl;
		} else {
			int idx2 = lower_bound(ar.begin() + mark, ar.end(), x) - ar.begin();
			if(ar[idx2] == x) {
				cout << idx2 << endl;
			} else {
				cout << -1 << endl;
			}
		}
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
