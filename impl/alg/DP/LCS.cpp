#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(size_t i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)

using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;

using namespace std;

int lcs_length(const string& a, const string& b){
	vector<vector<int>> state(a.length() + 1);
	state[0].assign(b.size() + 1, 0);
	FOR(i, a.size()){
		state[i + 1].assign(b.size() + 1, -1);
		state[i + 1][0] = 0;
	}
	// Solve maximization problem
	FOR(i, a.size()){
		FOR(j, a.size()){
			if(a[i] == b[j]){
				state[i + 1][j + 1] = state[i][j] + 1;
			} else{
				state[i + 1][j + 1] = max(state[i][j + 1], state[i + 1][j]);
			}
		}
	}
	return state[a.size()][b.size()];
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	TEST{
		int t;
		string str1, str2;
		cin >> t >> t;
		cin >> str1 >> str2;
		cout << lcs_length(str1, str2) << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
