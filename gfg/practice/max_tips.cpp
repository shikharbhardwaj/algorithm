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

int dp[105][105][105];
int A[105], B[105];
int X, Y, N;

int max_tip(int i, int j, int k) {
	if(i == N)
		return 0;
	if(dp[i][j][k] == -1) {
		if(j == X) {
			dp[i][j][k] =  B[i] + max_tip(i + 1, j, k + 1);
		} else if(k == Y) {
			dp[i][j][k] =  A[i] + max_tip(i + 1, j + 1, k);
		} else {
			dp[i][j][k] =  max(A[i] + max_tip(i + 1, j + 1, k), B[i] + max_tip(i + 1, j, k + 1));
		}
	}
	return dp[i][j][k];
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
		cin >> N >> X >> Y;
		FOR(i, N) {
			cin >> A[i];
		}
		FOR(i, N) {
			cin >> B[i];
		}
		FOR(i, N) {
			FOR(j, X + 1) {
				FOR(k, Y + 1) {
					dp[i][j][k] = -1;
				}
			}
		}
		cout << max_tip(0, 0, 0) << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
