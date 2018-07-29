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

pii get_surface(int l, int r, const vi& ar) {
	int max1 = -1, max2 = -1, m1, m2;
	for(int i = l; i <= r; ++i) {
		if(ar[i] > max1) {
			m2 = m1;
			max2 = max1;
			m1 = i;
			max1 = ar[i];
		} else if(ar[i] > max2) {
			m2 = i;
			max2 = ar[i];
		}
	}
	return make_pair(min(m1, m2), max(m1, m2));
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
		vi heights(N);

		FOR(i, N) {
			cin >> heights[i];
		}
		int ans = 0;
		vector<pii> ranges;
		ranges.emplace_back(0, N - 1);
		while(!ranges.empty()) {
			auto sch = ranges.back();
			auto rem = get_surface(sch.first, sch.second, heights);
			if(rem.second - rem.first > 1) {
				// Relax the surface.
				int vol = min(heights[rem.first], heights[rem.second]) *
				(rem.second - rem.first - 1);
				for(int i = rem.first + 1; i < rem.second; ++i) {
					vol -= heights[i];
				}
				ans += vol;
			}
			ranges.pop_back();
			// Add the split ranges.
			if(sch.first < rem.first - 1) {
				ranges.emplace_back(sch.first, rem.first);
			}
			if(sch.second > rem.second + 1) {
				ranges.emplace_back(rem.second, sch.second);
			}
		}
		cout << ans << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
