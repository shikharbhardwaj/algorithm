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

		FOR(i, N) {
			cin >> ar[i];
		}

		map<int, int> next_largest;

		vi stack;
		for(int i = 0; i < N; ++i) {
			if(stack.empty()) {
				stack.push_back(ar[i]);
				continue;
			}
			int cur = ar[i];
			while(!stack.empty() && cur > stack.back()) {
				next_largest[stack.back()] = cur;
				stack.pop_back();
			}
			stack.push_back(cur);
		}

		for(int i = 0; i < N; ++i) {
			if(next_largest.find(ar[i]) == next_largest.end()) {
				cout << -1 << " ";
			} else {
				cout << next_largest[ar[i]] << " ";
			}
		}
		cout << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
