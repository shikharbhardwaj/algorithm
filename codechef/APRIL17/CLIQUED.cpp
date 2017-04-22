#include <algorithm>
#include <unordered_map>
#include <list>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
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

int N, K, X, M, S;

using pi = pair<int, int>;

unordered_map<int, list<pi>> adj_list;
vector<long long> weights;

int get_weight(int u, int v){
	return weights[find_if(adj_list[u].begin(), adj_list[u].end(), [&](const pair<int, int> &in){
		return in.first == v;
	})->second];
}

unordered_map<int, int> dists;
struct min_heap_pairs{
	vector<pi> data;
	unordered_map<int, int> idx;

	min_heap_pairs() {
		data.push_back(make_pair(0, 0));
	}

	void siftup(int i){
		if(i == 1){
			return;
		}
		int parent = i / 2;
		int min = parent;
		if(dists[data[parent].first] > dists[data[i].first]){
			min = i;
		}
		if(min != parent){
			idx[data[min].first] =  parent;
			idx[data[parent].first] = min;
			swap(data[min], data[parent]);
			siftup(parent);
		}
	}
	void siftdown(int i){
		if(2 * i >= data.size()){
			return;
		}
		int parent = i;
		int left = 2 * parent;
		int right = 2 * parent + 1;
		int min = parent;
		if(dists[data[parent].first] > dists[data[left].first]){
			min = left;
		}
		if(right < data.size() && dists[data[min].first] > dists[data[right].first]){
			min = right;
		}
		if(min != parent){
			idx[data[min].first] =  parent;
			idx[data[parent].first] = min;
			swap(data[min], data[parent]);
			siftdown(min);
		}
	}
	void insert(const pi &in){
		data.push_back(in);
		idx[in.first] = data.size() - 1;
		siftup(data.size() - 1);
	}
	void decrease_key(const pi &in){
		data[idx[in.first]] = in;
		siftup(idx[in.first]);
	}
	pi pop(){
		auto ret = data[1];
		swap(data[1], data[data.size() - 1]);
		idx[data[1].first] = 1;
		data.pop_back();
		siftdown(1);
		idx.erase(ret.first);
		return ret;
	}
	bool empty(){
		return data.size() == 1;
	}
};

const int MAX = numeric_limits<int>::max();
void Djikstra(int s){
	dists.clear();

	min_heap_pairs minq;

	for(int i = 1; i <= N; ++i){
		if(i == s){
			dists[i] = 0;
		} else{
			dists[i] = MAX;
		}
		minq.insert(make_pair(i, dists[i]));
	}
	while(!minq.empty()){
		pi next = minq.pop();
		int u = next.first;
		// cout << "Visit " << u << endl;

		for(auto it = adj_list[u].begin(); it != adj_list[u].end(); ++it){
			int v = it->first;
			int alt = next.second + get_weight(u, v);
			if( dists[u] != MAX && alt < dists[v] ){
				dists[v] = alt;
				minq.decrease_key(make_pair(v, alt));
			}
		}
		// cout << dists << endl;
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
		adj_list.clear();
		weights.clear();
		cin >> N >> K >> X >> M >> S;
		int a, b, c;
		FOR(i, M){
			cin >> a >> b >> c;
			adj_list[a].push_back(make_pair(b, i));
			adj_list[b].push_back(make_pair(a, i));
			weights.push_back(c);
		}
		weights.push_back(X);
		for(int i = 1; i <= K; ++i){
			for(int j = 1; j <= K; ++j){
				if(i != j){
					adj_list[i].push_back(make_pair(j, M));
					adj_list[j].push_back(make_pair(i, M));
				}
			}
		}
		Djikstra(S);
		for(int i = 1; i <= N; ++i){
			cout << dists[i] << ' ';
		}
		cout << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}