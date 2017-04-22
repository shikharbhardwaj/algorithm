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
	string pos;
	cin >> pos;
	int cur = pos[0], cur_l = 1;
	bool danger = false;
	for(size_t i = 1; i < pos.size(); ++i){
		if(pos[i] == cur){
			++cur_l;
		} else{
			cur_l = 1;
			cur = pos[i];
		}
		if(cur_l == 7){
			danger = true;
			break;
		}
	}
	if(danger){
		cout << "YES\n";
	} else{
		cout << "NO\n";
	}

#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
