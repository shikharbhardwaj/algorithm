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
		int N, zero_cnt = 0, cur, prev;

		cin >> N;
		vi ans;
		cin >> prev;
		if(prev == 0) {
			++zero_cnt;
		} else {
			ans.push_back(prev);
		}
		FOR(i, N - 1) {
			cin >> cur;
			if(cur == 0) {
				prev = 0;
				++zero_cnt;
			} else if(cur == prev) {
				ans.back() = 2 * ans.back();
				++zero_cnt;
				prev = 0;
			} else {
				ans.push_back(cur);
				prev = cur;
			}
		}
		for(auto e : ans) {
			cout << e << " ";
		}
		while(zero_cnt--) {
			cout << "0 ";
		}
		cout << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
