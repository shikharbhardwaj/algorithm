#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <limits>
#include <vector>
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

// Implements the Unbounded Knapsack algorithm (minimum coin exchange)
// algorithm

template <typename T>
void optimize(T S, const vector<T>& vals, vector<T>& min_coins){
	min_coins.assign(S + 1, numeric_limits<T>::max());
	min_coins[0] = 0;
	for(T i = 1; i <= S; ++i){
		for(size_t j = 0; j < vals.size(); ++j){
			if(vals[j] <= i){
				min_coins[i] = min(min_coins[i], min_coins[i - vals[j]] + 1);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	int n, S;
	cin >> n >> S;
	vector<int> vals(n);
	for(int i = 0; i < n; ++i){
		cin >> vals[i];
	}
	vector<int> cnt;
	optimize(S, vals, cnt);
	cout << cnt << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
