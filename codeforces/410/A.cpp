#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
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
	string str;
	cin >> str;
	string first_half = str.substr(0, str.size() / 2);
	string second_half = str.substr(ceil(float(str.size()) / 2), str.size() / 2);
	reverse(second_half.begin(), second_half.end());
	int num_diff = 0;
	for(size_t i = 0; i < str.size() / 2; ++i){
		if(first_half[i] != second_half[i]){
			num_diff++;
		}
	}
	if(str.size() % 2 == 0){
		if(num_diff != 1){
			cout << "NO\n";
		} else{
			cout << "YES\n";
		}
	} else{
		if(num_diff > 1){
			cout << "NO\n";
		} else{
			cout << "YES\n";
		}
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif
}
