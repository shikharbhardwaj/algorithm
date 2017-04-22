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
int memo[100005];

int cost(int i, const std::string &in){
	int cost = 0;
	for(int j = i - 1; j >= 0; --j){
		if(in[j] == '1')
			break;
		++cost;
	}
	return cost;
}
int max_time(){
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
	while(T--){
		string S;
		cin >> S;
		reverse(S.begin(), S.end());
		for(size_t i = 0; i < S.size(); ++i){
			memo[i] = -1;
		}
		memo[0] = 0;
		cout << max_time(S.size() - 1, S) << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}