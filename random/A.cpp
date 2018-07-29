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

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	ll l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;
	// Check if the ranges agree.
	bool found = false;
	for(ll i = x; i <= y && !found; ++i) {
		ll test = i * k;

		ll left = l, right = r + 1;
		while(left < right) {
			ll mid = left + (right - left) / 2;

			if(mid == test) {
				found = true;
				break;
			} else if(mid < test) {
				left = mid + 1;
			} else{
				right = mid;
			}
		}
	}

	if(found) {
		cout << "YES\n";
	} else{
		cout << "NO\n";
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
