#include <algorithm>
#include <fstream>
#include <limits>
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

using wtype = long long;
long long N, K, X, M, S;

struct edge { 
	int to; 
	wtype length; 
	edge() = default;
	edge(int to, wtype length) : to(to), length(length) {}
};

void dijkstra(const vector< vector<edge> > &graph, int source) {
	wtype INT_MAX = numeric_limits<long long>::max();
	vector<wtype> min_distance( graph.size(), INT_MAX );
	min_distance[source] = 0;
	set<pair<wtype, int>> active_vertices;
	active_vertices.insert({0, source});

	while (!active_vertices.empty()) {
		int where = active_vertices.begin()->second;

		active_vertices.erase( active_vertices.begin() );
		for (auto ed : graph[where]) {
			if (min_distance[ed.to] > min_distance[where] + ed.length) {
				active_vertices.erase( { min_distance[ed.to], ed.to } );
				min_distance[ed.to] = min_distance[where] + ed.length;
				active_vertices.insert( { min_distance[ed.to], ed.to } );
			}
		}
	}
	int min_clique = min_element(min_distance.begin() + 1, min_distance.begin() + K + 1) - min_distance.begin();
	for(int i = 1; i <= K; ++i) {
		min_distance[i] = min(X + min_distance[min_clique], min_distance[i]);
	}

	active_vertices.clear();
	for(int i = 1; i <= K; ++i){
		active_vertices.insert({min_distance[i], i});
	}

	while (!active_vertices.empty()) {
		int where = active_vertices.begin()->second;

		active_vertices.erase( active_vertices.begin() );
		for (auto ed : graph[where]) {
			if (min_distance[ed.to] > min_distance[where] + ed.length) {
				active_vertices.erase( { min_distance[ed.to], ed.to } );
				min_distance[ed.to] = min_distance[where] + ed.length;
				active_vertices.insert( { min_distance[ed.to], ed.to } );
			}
		}
	}
	for(int i = 1; i <= N; ++i){
		cout << min_distance[i] << " ";
	}
	cout << endl;
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
		vector<vector<edge>> adj_list;
		cin >> N >> K >> X >> M >> S;
		adj_list.assign(N + 1, {});
		int a, b, c;
		for(int i = 0; i < M; ++i){
			cin >> a >> b >> c;
			adj_list[a].emplace_back(b, c);
			adj_list[b].emplace_back(a, c);
		}
		dijkstra(adj_list, S);
	}	
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
