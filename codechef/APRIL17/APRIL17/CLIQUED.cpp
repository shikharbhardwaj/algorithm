#include <algorithm>
#include <limits>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <unordered_map>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;

using namespace std;

unordered_map<int, list<pair<int, int>>> adj_list;
vector<int> weights;

int T, N, K, X, M, S;


int get_weight(int u, int v){
	if(u <= K && v <= K){
		return X;
	}
	auto &li = adj_list[u];
	auto edge = *std::find_if(li.begin(), li.end(), [&](const pair<int, int> &in){
		return in.first == v;
	});
	return weights[edge.second];
}
// Djikstra state

struct compare_node{
	bool operator()(pair<int, int> l, pair<int, int> r){
		return dists[l.first] > dists[r.first];
	}
};

// Cases 
// what if the thing is in the clique?
// Insight, make the clique into one node?

unordered_map<int, int> Djikstra(int s){
	unordered_map<int, int> dists;
	set<int> to_visit;
	int to_clique = numeric_limits<int>::max();

	for(int i = 1; i <= N; ++i){
		dists[i] = numeric_limits<int>::max();
		to_visit.insert(i);
	}

	dists[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare_node> min_q;
	for(auto e : adj_list[s]){
		min_q.push(e);
	}
	while(!to_visit.empty()){
		int u = min_q.top().first;
		min_q.pop();
		to_visit.erase(u);
	}
	return dists;
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	cin >> T;
	while(T--){
		adj_list = {};
		weights = {};
		cin >> N >> K >> X >> M >> S;
		int a, b, c;
		for (int i = 0; i < M; ++i) {
			cin >> a >> b >> c;
			adj_list[a].push_back(make_pair(b, i));
			adj_list[b].push_back(make_pair(a, i));
			weights.push_back(c);
		}
		cout << weights << endl;
		cout << adj_list << endl;
		Djikstra(1);
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
