#include <algorithm>
#include <cassert>
#include <chrono>
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

const long long prime_limit = 1000005;

int spf[prime_limit];

void pollard_rho(){
}

long long score(long long n){
	if(n == 1){
		return 0;
	}
	if(n <= prime_limit){
		if(!is_composite[n]){
			return 2;
		}
	}
	vector<int> powers;
	// Alternative factorization
	auto prime_mark = lower_bound(primes.begin(), primes.end(), ceil(sqrt(n))) - primes.begin(); 
	for(long long i = 0; i <= prime_mark; ++i){
		if(n == 1){
			break;
		}
		if(n % primes[i] == 0){
			powers.push_back(0);
			while(n % primes[i] == 0){
				powers.back()++;
				n /= primes[i];
			}
		}
	}
	if(n > 1){
		powers.push_back(1);
	}

	long long ans = 1;

	for(size_t i = 0; i < powers.size(); ++i){
		ans *= (powers[i] + 1);
	}
	size_t cur;
	do{
		cur = 1;
		sort(powers.begin(), powers.end(), greater<int>());
		powers[0]--;
		for(size_t i = 0; i < powers.size(); ++i){
			cur *= (powers[i] + 1);
		}
		ans += cur;
	} while(cur != 1);

	return ans - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif
	sieve();
	long long a, b;
	cin >> a >> b;
	long long ans = 0;
	for(long long i = a; i <= b; ++i){
		ans += score(i);
	}
	cout << ans << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
