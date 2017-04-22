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

int steps_needed(const string& str1, const string& str2){
	if(str1 == str2){
		return 0;
	} else{
		size_t rot_num = 1;
		while(rot_num != str1.size()){
			string shim = str1;
			rotate(shim.begin(), shim.begin() + rot_num, shim.end());
			if(shim == str2){
				return rot_num;
			}
			++rot_num;
		}
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	vector<string> strs;
	int n;
	cin >> n;
	strs.assign(n, "");
	FOR(i, n){
		cin >> strs[i];
	}
	int min = 50000;
	FOR(i, n){
		int cur = 0;
		FOR(j, n){
			if(i == j){
				continue;
			}
			int steps = steps_needed(strs[j], strs[i]);
			if(steps == -1){
				cout << -1 << endl;
				return 0;
			}
			cur += steps;
		}
		if(cur < min){
			min = cur;
		}
	}
	cout << min << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
