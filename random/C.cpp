#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <cmath>
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

vector<vector<int>> adj_list;
vector<int> values, ans;
vector<bool> visited;
map<int, set<int>> divisors;
set<int> path;
int height;

void dfs(int u) {}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	int V, u, v;
	cin >> V;

	values.resize(V + 1);
	ans.resize(V + 1);
	for(int i = 0; i < V; ++i) {
		cin >> values[i + 1];
	}

	adj_list.resize(V + 1);

	for(int i = 1; i < V; ++i) {
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	visited.assign(V + 1, false);
	dfs(1);

	copy(ans.begin() + 1, ans.end(), ostream_iterator<int>(cout, " "));

#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
