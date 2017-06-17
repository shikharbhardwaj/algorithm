#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
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
	TEST{
		ll N, L, A, B;
		cin >> N >> L >> A >> B;
		vll starts(N), dp(N + 1);
		multiset<ll> heads;
		FOR(i, N){
			cin >> starts[i];
			heads.insert(starts[i]);
		}
		sort(starts.begin(), starts.end());
		ll range = B - (L * N); // The last start can happen here
		ll num_pos, num_neg, num_zero;
		num_zero = num_neg = num_pos = 0;
		dp[0] = max(A - starts[0], starts[0] - A);
		(A - starts[0] > 0) ? ++num_pos :0;
		(A - starts[0] < 0) ? ++num_neg:0;
		(A - starts[0] == 0) ? ++num_zero:0;
		FOR(i, N - 1){
			dp[i + 1] = dp[i] + max(A + L * (i + 1) - starts[i + 1], starts[i + 1] - (A + L * (i + 1)));
			(A + L * (i + 1) - starts[i + 1] > 0) ? ++num_pos :0;
			(A + L * (i + 1) - starts[i + 1] < 0) ? ++num_neg:0;
			(A + L * (i + 1) - starts[i + 1] == 0) ? ++num_zero:0;
		}
		ll cost = dp[N - 1];
		ll min_cost = cost;
		for(ll i = A + 1; i <= range; ++i){
			num_pos += num_zero;
			num_zero = heads.count(i);
			num_neg -= num_zero;
			cost += (num_pos + num_neg - num_zero) * L;
			min_cost = min(cost, min_cost);
		}
		cout << min_cost << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
