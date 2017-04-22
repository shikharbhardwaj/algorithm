#include <algorithm>
#include <fstream>
#include <map>
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
int N, Q;
int ar[100005];
int cnt[100005];
int cnt_rev[100005];

map<int, vector<int>> positions;

void query(int l, int r, int k){
	// cout << "Called with [" << l << ", " << r << "] :: " << k << endl;
	if(positions.find(k) == positions.end()){
		cout << "0" << endl;
	} else{
		// Take care of the ends
		// cout << "Search in : " << vector<long long>({l + cnt_rev[l], r - cnt[r]}) << endl;
		int num_search = 0;
		if(l + cnt_rev[l] <= r - cnt[r]){
			auto a = lower_bound( positions[k].begin(), positions[k].end(), l + cnt_rev[l]) - positions[k].begin();
			auto b = upper_bound( positions[k].begin(), positions[k].end(), r - cnt[r]) - positions[k].begin();
			num_search += b - a;
		}
		// Check left
		num_search += (cnt_rev[l] >= k);
		// Check right
		if(l + cnt_rev[l] <= r){
			num_search += (cnt[r] >= k);
		}
		cout << num_search << endl;
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
	TEST{
		cin >> N >> Q;
		FOR(i, N){
			cin >> ar[i];
		}
		int L, R, K;
		cnt[0] = 1;
		int cur = ar[0];
		for(int i = 1; i < N; ++i){
			if(ar[i] == cur){
				cnt[i] = cnt[i - 1] + 1;
			} else{
				cur = ar[i];
				cnt[i] = 1;
			}
		}
		cnt_rev[N - 1] = 1;
		cur = ar[N - 1];
		for(int i = N - 2; i >= 0; --i){
			if(ar[i] == cur){
				cnt_rev[i] = cnt_rev[i + 1] + 1;
			} else{
				cur = ar[i];
				cnt_rev[i] = 1;
			}
		}
		// Construct a map
		positions.clear();
		for(int i = 0; i < N; ++i){
			if(positions.find(cnt[i]) != positions.end()){
				positions[cnt[i]].push_back(i);
			} else{
				positions[cnt[i]] = {i};
			}
		}
		// cout << positions << endl;
		FOR(i, Q){
			cin >> L >> R >> K;
			query(L - 1, R - 1, K);
		}
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}