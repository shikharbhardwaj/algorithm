#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>
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
using pii = std::pair<int, int>;

using namespace std;


int num_components, cur_time;
vi times;
vi deg_back_edges;

void dfs(int src, const vector<vi>& graph, vector<bool>& visited){
	++cur_time;
	visited[src] = true;
	times[src] = cur_time;
	for(auto v : graph[src]){
		if(!visited[v]){
			dfs(v, graph, visited);
		} else{
			if(times[src] < times[v]){
				deg_back_edges[min(graph[v].size(), graph[src].size())]++;
			}
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
	TEST{
		int N, E;
		cin >> N >> E;
		vector<vi> adj_list(N + 1);
		set<pii> edge_set;
		size_t max_deg = 0;
		FOR(i, E){
			int u, v;
			cin >> u >> v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
			max_deg = max(adj_list[u].size(), max_deg);
			max_deg = max(adj_list[v].size(), max_deg);
			edge_set.insert(make_pair(u, v));
		}
		set<pair<int, pii>> edge_metric;
		for(auto e : edge_set){
			auto u = e.first;
			auto v = e.second;
			auto min_deg = min(adj_list[u].size(), adj_list[v].size());
			edge_metric.insert({min_deg, make_pair(u, v)});
		}
		vi deg_edges(max_deg + 1, 0);
		for(auto e : edge_metric){
			deg_edges[e.first]++;
		}
		deg_back_edges.assign(max_deg + 1, 0);
		// Run DFS, get the number of connected components
		cur_time = num_components = 0;
		vector<bool> visited(N + 1, false);
		times.assign(N + 1, 0);

		for(int i = 1; i <= N; ++i){
			if(!visited[i]) {
				dfs(i, adj_list, visited);
				++num_components;
			}
		}
		int removed_tree_edges = num_components - 1;
		FOR(i, N){
			if(i <= max_deg){
				removed_tree_edges += (deg_edges[i] - deg_back_edges[i]);
			}
			cout << removed_tree_edges << " ";
		}
		assert(removed_tree_edges == N - 1);
		cout << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}