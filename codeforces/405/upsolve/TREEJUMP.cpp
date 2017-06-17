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

using edge = pair<int, ll>;

ll& cnt(edge& e) {return e.second;}
int& to(edge& e) {return e.first;}

vector<vector<edge>> graph;

set<int> visited;
void dfs(int src) {
	visited.insert(src);

	for(auto &e : graph[src]){
		cnt(e)++;
		if(visited.find(to(e)) == visited.end()){
			dfs(to(e));
			visited.erase(to(e));
		}
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
	int N, K;
	cin >> N >> K;
	graph.resize(N + 1);
	int u, v;
	FOR(i, N - 1){
		cin >> u >> v;
		graph[u].emplace_back(v, 0);
		graph[v].emplace_back(u, 0);
	}
	cout << graph << endl;
	dfs(1);
	cout << graph << endl;

	int ans = 0;
	FOR(i, N){
		for(auto e : graph[i + 1]){
			ans += cnt(e);
		}
	}
	cout << ans << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
