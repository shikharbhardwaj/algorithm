#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)

using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;

using namespace std;

// Solve 1D RMQ using Sparse table.
int table[100005][18];

void init_table(const vector<int>& ar) {
	for(size_t i = 0; i < ar.size(); ++i) {
		table[i][0] = ar[i];
	}

	// Now fill the rest of the table.
	for(size_t j = 1; j <= floor(log2(ar.size())); ++j) {
		for(size_t i = 0; i + (1 << j) <= ar.size(); ++i) {
			table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r) {
	int len = r - l + 1;
	int k = log2(len);

	return min(table[l][k], table[r + 1 - (1 << k)][k]);
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		int N, Q;
		cin >> N >> Q;
		vector<int> ar(N);
		for(auto& e : ar)
			cin >> e;

		init_table(ar);

		// for(int i = 0; i < ar.size(); ++i) {
		// 	for(int j = 0; j <= log2(ar.size()); ++j) {
		// 		cout << table[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		int L, R;
		cout << "Scenario #" << i << ":" << endl;

		while(Q--) {
			cin >> L >> R;

			cout << query(L - 1, R - 1) << endl;
		}
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
