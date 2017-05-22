#include <algorithm>
#include <cstring>
#include <cstdio>
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
	int k;
	string str;
	cin >> k >> str;
	int ftable[26];
	memset(ftable, 0, sizeof(ftable));
	for(auto elem : str){
		ftable[elem - 'a']++;
	}
	bool valid = true;
	FOR(i, 26){
		if(ftable[i] % k){
			valid = false;
		}
	}
	if(valid){
		std::string token;
		for(int i = 0; i < 26; ++i){
			token += std::string(ftable[i] / k, 'a' + i);
		}
		for(int i = 0; i < k; ++i){
			cout << token;
		}
		cout << endl;
	} else{
		cout << "-1" << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
