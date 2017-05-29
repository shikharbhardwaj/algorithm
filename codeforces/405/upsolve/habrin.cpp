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

const ll mod = 1300031;
using namespace std;

struct edge{
	int to;
	ll weight;
	edge() = default;
	edge(int to, ll weight) : to(to), weight(weight) {}
};

ostream& operator<<(ostream& ost, const edge& arg){
	return ost << "(" << arg.to << " | " << arg.weight << ")";
}


vector<vector<edge>> graph;
vector<ll> cnt;

set<int> visited;
ll ans;

void dfs(int src, ll cost) {
	visited.insert(src);
	cnt[src] = 1;

	for(auto e : graph[src]) {
		if(visited.find(e.to) == visited.end()){
			dfs(e.to, e.weight);
			cnt[src] += cnt[e.to];
		}
	}
	ll add = (((cnt[src] % mod * (graph.size() - cnt[src] - 1) % mod) % mod) * (cost % mod)) % mod;
	ans += add;
	ans %= mod;
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	TEST {
		int N;
		cin >> N;
		graph.assign(N + 1, {});
		cnt.assign(N + 1, 0);
		visited.clear();
		ans = 0;

		int u, v;
		ll w;
		FOR(i, N - 1){
			cin >> u >> v >> w;
			graph[u].push_back({v, w});
			graph[v].push_back({u, w});
		}
		dfs(1, 0);
		cout << ans << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
