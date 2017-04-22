#include <algorithm>
#include <fstream>
#include <iostream>
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

int ar[102];

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i){
		cin >> ar[i];
	}
	// Find the nearest house he can buy
	int min_left = -1, min_right = n;
	for(int i = m - 1; i >= 0; --i){
		if(ar[i] != 0 && ar[i] <= k){
			min_left = i;
			break;
		}
	}
	for(int i = m + 1; i < n; ++i){
		if(ar[i] != 0 && ar[i] <= k){
			min_right = i;
			break;
		}
	}
	cout << min(m - min_left, min_right - m) << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}