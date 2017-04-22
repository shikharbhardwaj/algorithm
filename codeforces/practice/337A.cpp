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

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	int n, m;
	cin >> n >> m;
	vector<int> nums(m);
	FOR(i, m){
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	int cur_diff = numeric_limits<int>::max();
	for(int i = 0; i + n - 1 < m; ++i){
		cur_diff = min(cur_diff, nums[i + n - 1] - nums[i]);
	}
	cout << cur_diff << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}