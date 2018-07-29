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

vector<int> primes;

void gen() {
	vector<bool> seive(1e7 + 7, true);
	for(int i = 4; i < seive.size(); i += 2) {
		seive[i] = false;
	}
	primes.push_back(2);
	for(int i = 3; i < seive.size(); i += 2) {
		if(seive[i]) {
			primes.push_back(i);
			for(int j = 3; j * i < seive.size(); j += 2) {
				seive[j * i] = false;
			}
		}
	}
}

int primacity(int A, int B, int K) {
	// Find if the first k prime lies in [A, B]
	if(K > 8)
		return 0;
	
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
	int A, B, K;
	gen();
	while(T--) {
		cin >> A >> B >> K;
		cout << primacity(A, B, K) << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
