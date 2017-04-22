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

int spf[prime_limit + 1];
vector<int> primes;

void sieve(){
	spf[1] = 1;
	spf[2] = 2;
	for(int i = 3; i <= prime_limit; ++i){
		if(i % 2 == 0){
			spf[i] = 2;
		} else{
			spf[i] = i;
		}
	}
	primes.push_back(2);
	for(int i = 3; i * i <= prime_limit; i += 2){
		if(spf[i] == i){
			// This is a prime
			for(int j = i * i; j <= prime_limit; j += i){
				if(spf[j] == j){
					spf[j] = i;
				}
			}
		}
	}
	for(int i = 3; i <= prime_limit; i += 2){
		if(spf[i] == i){
			primes.push_back(i);
		}
	}
}

long long score(long long n){
	if(n == 1){
		return 0;
	}
	if(n <= prime_limit){
		if(spf[n] == n){
			return 2;
		}
	}
	vector<int> powers;
	// Alternative factorization
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
	cout << primes.size();
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}