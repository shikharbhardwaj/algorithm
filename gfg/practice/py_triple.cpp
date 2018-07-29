#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

vi pytho_primes;

bool is_perfect_square(int n) {
	if(n < 0) return false;
	int root = round(sqrt(n));
	return n == root * root;
}

void pre(int n) {
	vector<bool> mark(n, true);
	mark[1] = false;
	for(int i = 4; i < n; i += 2) {
		mark[i] = false;
	}
	for(int i = 3; i < n; i += 2) {
		if(mark[i]) {
			for(int j = 2 * i; j < n; j += i)
				mark[j] = false;
		}
	}

	for(int i = 5; i < n; ++i) {
		if(mark[i] && (i - 1) % 4 == 0) 
			pytho_primes.push_back(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	pre(128);
	TEST {
		int N;
		cin >> N;

		vi ar(N);

		FOR(i, N) {
			cin >> ar[i];
		}

		sort(ALL(ar));
		// Check if a pythogorean prime exists.
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
