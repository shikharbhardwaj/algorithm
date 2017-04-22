#include <algorithm>
#include <cmath>
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

int prime_facts(ull in){
	int cnt = 0;
	ull limit = sqrt(in), x = in;
	if(in % 2 == 0){
		cnt += 1;
		while(in % 2 == 0){
			in /= 2;
		}
	}
	for(ull i = 3; i <= limit; i += 2){
		if(in % i == 0){
			cnt += 1;
			if(cnt > 3) {
				return cnt;
			}
			while(in % i == 0){
				in /= i;
			}
		}
	}
	if(in > 1 && in != x){
		++cnt;
	}
	return cnt;
}
int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	int n;
	ull in;
	std::cin >> n;
	FOR(i, n){
		std::cin >> in;
		if(prime_facts(in) == 1){
			std::cout << "YES\n";
		} else{
			std::cout << "NO\n";
		}
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
