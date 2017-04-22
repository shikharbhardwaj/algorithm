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

bool is_composite[prime_limit + 1];
vector<long long> primes;

void sieve(){
	is_composite[0] = is_composite[1] = true;
	is_composite[2] = false;
	for(long long i = 4; i <= prime_limit; i += 2){
		is_composite[i] = true;
	}
	for(long long i = 3; i <= sqrt(prime_limit); i += 2){
		if(!is_composite[i]){
			// This is a prime number
			for(long long j = i * i; j <= prime_limit; j += i){
				is_composite[j] = true;
			}
		}
	}
	primes.push_back(2);
	for(long long i = 3; i <= prime_limit; i += 2){
		if(!is_composite[i]){
			primes.push_back(i);
		}
	}
}
const int memo_limit = 100000;
int memo[memo_limit];

long long score(long long n){
	if(n == 1){
		return 0;
	}
	if(n < memo_limit && memo[n] != 0){
		return memo[n];
	}
	if(n <= prime_limit){
		if(!is_composite[n]){
			if(n < memo_limit){
				memo[n] = 2;
			}
			return 2;
		}
	}
	vector<pair<int, long long>> powers;
	const long long n_original = n;
	long long target = n;
	// Alternative factorization
	auto prime_mark = lower_bound(primes.begin(), primes.end(), ceil(sqrt(n))) - primes.begin(); 
	for(long long i = 0; i <= prime_mark; ++i){
		if(n == 1){
			break;
		}
		if(n % primes[i] == 0){
			powers.push_back(make_pair(0, primes[i]));
			while(n % primes[i] == 0){
				powers.back().first++;
				n /= primes[i];
			}
		}
	}
	if(n > 2){
		powers.push_back(make_pair(1, n));
	}

	long long ans = 1;

	for(size_t i = 0; i < powers.size(); ++i){
		ans *= (powers[i].first + 1);
	}
	size_t cur;
	vector<int> fillers;
	do{
		cur = 1;
		sort(powers.begin(), powers.end(), 
			[](const pair<int, long long> &lhs, const pair<int, long long> &rhs){
				return lhs.first > rhs.first;
			});
		powers[0].first--;
		target /= powers[0].second;
		if(target < memo_limit && memo[target] != 0){
			ans += memo[target] + 1;
			for(auto elem : fillers){
				memo[elem] += memo[target] + 1;
			}
			break;
		} 		
		for(size_t i = 0; i < powers.size(); ++i){
			cur *= (powers[i].first + 1);
		}
		if(target < memo_limit && memo[target] == 0 && target != 1){
			fillers.push_back(target);
		}
		for(auto elem : fillers){
			memo[elem] += cur;
		}
		ans += cur;
	} while(cur != 1);
	for(auto elem : fillers){
		memo[elem]--;
	}

	if(n_original < memo_limit){
		memo[n_original] = ans - 1;
	}
	return ans - 1;
}
void fill_memo(){
	for(int i = 2; i < memo_limit; ++i){
		score(i);
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
	sieve();
	fill_memo();
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