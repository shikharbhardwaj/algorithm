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

int capacity[1001][1001], flow[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		FOR(i, N) {
			FOR(j, N) {
				flow[i + 1][j + 1] = capacity[i + 1][j + 1] = 0;
			}
		}
		FOR(i, M) {
			cin >> u >> v;
			cin >> capacity[u][v];
			capacity[v][u] = capacity[u][v];
		}
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
