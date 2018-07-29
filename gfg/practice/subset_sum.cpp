#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
#include <cstring>
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
		vi nums(N);
		int sum = 0;
		for(auto& e : nums) {
			cin >> e;
			sum += e;
		}

		int target = sum / 2;
		if(sum % 2 != 0) {
			cout << "NO" << endl;
			continue;
		}
		int dp[N + 1][target + 1];

		for(int i = 1; i <= N; ++i)  {
			dp[i][0] = true;
		}

		for(int i = 0; i <= target; ++i) {
			dp[0][i] = false;
		}

		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= target; ++j) {
				if(j < nums[i - 1]) {
					dp[i][j] = dp[i - 1][j];
				} else {
					dp[i][j] = dp[i - 1][j - nums[i -1]] || dp[i - 1][j];
				}
			}
		}

		cout << ((dp[N][target]) ? "YES" : "NO") << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
