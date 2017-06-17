#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <limits>
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

ll cost(int id, long long total, const vll& max_length_possible){
	ll cost = 0;
	ll n = max_length_possible[id];
	cost += total - n * n;
	return cost;
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	TEST {
		long long n, total;
		cin >> n;
		vll elems(n), prev_len(n), next_len(n);
		total = 0;
		FOR(i, n){
			cin >> elems[i];
			total += elems[i];
		}
		// Pre compute the max_length_possible here
		long long cur_len = 0;
		FOR(i, n) {
			cur_len = min(cur_len + 1, elems[i]);
			prev_len[i] = cur_len;
		}
		cur_len = 0;
		for (int i = n - 1; i >= 0; --i) {
			cur_len = min(cur_len + 1, elems[i]);
			next_len[i] = cur_len;
		}
		vll max_length_possible(n);
		FOR(i, n){
			max_length_possible[i] = min(prev_len[i], next_len[i]);
		}
		long long min_cost = numeric_limits<ll>::max();
		FOR(i, n){
			min_cost = min(min_cost, cost(i, total, max_length_possible));
		}
		cout << min_cost << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
