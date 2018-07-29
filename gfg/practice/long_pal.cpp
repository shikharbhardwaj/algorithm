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
		string in;
		cin >> in;
		int ans = 1, left = 0, right = 1;
		for(int i = 0; i < in.size() - 1; ++i) {
			int j = i - 1, k = i + 1;
			while(j >= 0 && k < in.size()) {
				if(in[j] != in[k]) break;
				--j;
				++k;
			}
			++j; --k;
			if(k - j + 1> ans) {
				ans = k - j + 1;
				left = j;
				right = k + 1;
			}

			j = i; k = i + 1;
			while(j >= 0 && k < in.size()) {
				if(in[j] != in[k]) break;
				--j;
				++k;
			}
			++j; --k;
			if(k - j + 1 > ans) {
				ans = k - j + 1;
				left = j;
				right = k + 1;
			}
		}
		while(left != right) {
			cout << in[left];
			++left;
		}
		cout << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
