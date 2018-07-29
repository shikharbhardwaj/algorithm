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
		int N, prev, cur;
		cin >> N;
		cin >> prev;
		vi sell_days;
		FOR(i, N - 1) {
			cin >> cur;
			if(cur - prev < 0) {
				sell_days.push_back(i);
			}
			if(cur - prev > 0 && i == N - 2)
				sell_days.push_back(N - 1);
			prev = cur;
		}

		int buy_day = 0;
		for(auto e : sell_days) {
			if(buy_day != e)
				cout << "(" << buy_day << " " << e << ") ";
			buy_day = e + 1;
		}
		if(sell_days.size() == 1 && sell_days[0] == 0) {
			cout << "No Profit";
		}
		cout << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
