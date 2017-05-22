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

const int prime_limit = 1e6 + 5;
bool prime[prime_limit + 1];
long long a, b;
vector<vector<long long>> dpf;

void pre() {
	dpf.assign(b - a + 1, {});
	prime[0] = prime[1] = false;
	for(int i = 2; i <= prime_limit; ++i){
		prime[i] = true;
	}
	for(long long cur = a + a % 2; cur <= b; cur += 2){
		dpf[cur - a].push_back(2);
	}
	for(int i = 4; i <= prime_limit; i += 2){
		prime[i] = false;
	}
	for(long long i = 3; i <= prime_limit; i += 2){
		if(prime[i]) {
			// This is a prime
			// Generate the distinct prime factors
			long long cur = a - a % i;
			cur += i * (ceil(double(a - cur) / i));
			while(cur <= b){
				dpf[cur - a].push_back(i);
				cur += i;
			}
			for(long long j = i * i; j <= prime_limit; j += 2 * i){
				prime[j] = false;
			}
		}
	}
}

long long score(long long c){
	if(c == 1){
		return 0;
	}
	if(c <= prime_limit && prime[c] == true){
		return 2;
	} else{
		vector<int> powers;
		for(auto e : dpf[c - a]){
			powers.push_back(0);
			while(c % e == 0){
				powers.back()++;
				c /= e;
			}
		}
		if(c > 2){
			powers.push_back(1);
		}
		long long ans = 0, cur = 1;
		do{
			sort(powers.begin(), powers.end(), greater<int>());
			cur = 1;
			for(auto e : powers){
				cur *= (e + 1);
			}
			powers[0]--;
			ans += cur;
		} while(cur != 2);
		return ans;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	cin >> a >> b;
	pre();
	long long ans = 0;
	for(long long cur = a; cur <= b; ++cur){
		ans += score(cur);
	}
	cout << ans << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
