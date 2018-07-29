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

int find_max(int i, int j, const vi& ar) {
	if(j - i <= 3) {
		int max = i;
		if(i + 1 < j && ar[max] < ar[i + 1])
			max = i + 1;
		if(i + 2 <  j && ar[max] < ar[i + 2])
			max = i + 2;
		return max;
	}
	int mid = (i + j) / 2;
	if(ar[mid] < ar[mid + 1]) return find_max(mid, j, ar);
	return find_max(i, mid + 1, ar);
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
		cin >> N >> x;

		vi ar(N);
		int max_idx = 0;
		FOR(i, N) {
			cin >> ar[i];
		}
		int idx = find_max(0, N, ar);
		int ans;
		auto it = lower_bound(ar.begin(), ar.begin() + idx, x);
		bool found = false;
		if(it != ar.begin() + idx && *it == x) {
			found = true;
			ans = distance(ar.begin(), it);
		}
		if(!found) {
			auto it2 = lower_bound(ar.rbegin(), ar.rbegin() + N - idx, x);
			if(it2 != ar.rbegin() + N - idx && *it2 == x) {
				found = true;
				ans = (N - 1) + distance(it2, ar.rbegin());
			}
		}
		if(found) {
			cout << ans << endl;
		} else {
			cout << "OOPS! NOT FOUND" << endl;
		}
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
