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

string generate_name(int i){
	return string(1, char('A' + i / 26)) + string(1, char('a' + (i) % 26));
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	int N, K;
	cin >> N >> K;
	vector<bool> repeat(N, false);
	for(int i = K - 1; i < N; ++i){
		string in;
		cin >> in;
		repeat[i] = (in == "NO");
	}
	vector<string> names(N); // The names of the N soldiers
	FOR(i, N){
		names[i] = generate_name(i + 2);
	}
	FOR(i, N) {
		if(repeat[i]){
			names[i] = names[i - K + 1];
		}
	}
	FOR(i, N){
		cout << names[i] << " ";
	}
	cout << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
