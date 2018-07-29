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

// Implementation of Prim's MST algorithm

struct edge{
	int to;
	float w;
};

std::ostream &operator<<(std::ostream &os, edge const& inst){
	return os << "(" << inst.to << ", " << inst.w << ")";
}

vector<vector<edge>> adj_list;


void MST_Prim() {
	set<pair<int, int>> active;
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	int V, E;
	cin >> V >> E;
	adj_list.assign(V + 1, {});
	FOR(i, E){
		int u, v;
		float w;
		cin >> u >> v >> w;
		adj_list[u].push_back({v, w}); // Directed graph
	}
	for_each(adj_list.begin(), adj_list.end(), [](const vector<edge> &in){
		cout << in << endl;
	});

#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
