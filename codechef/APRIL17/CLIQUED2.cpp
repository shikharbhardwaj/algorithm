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
long long N, K, X, M, S;
using pll = pair<int, long long>;

vector<vector<pll>> adj_list;

vector<pll> p_queue;
vector<int> idx;
int p_sz;

long long dist(int i){
	return p_queue[i].second;
}

void siftup(size_t i) {
	if(i == 1){
		return;
	}
	int parent = i / 2;

	if(dist(parent) > dist(i)){
		idx[p_queue[parent].first] = i;
		idx[p_queue[i].first] = parent;
		swap(p_queue[i], p_queue[parent]);
		siftup(parent);
	}
} 
void siftdown(size_t i) {
	if(2 * i >= p_sz){
		return;
	}
	int left = 2 * i;
	int right = 2 * i + 1;
	size_t min = i;
	if(dist(left) < dist(i)){
		min = left;
	}
	if(2 * i + 1 < p_sz && dist(right) < dist(min)){
		min = right;
	}
	if(min != i){
		idx[p_queue[i].first] = min;
		idx[p_queue[min].first] = i;
		swap(p_queue[i], p_queue[min]);
		siftdown(min);
	}
}
void insert(const pll& in) {
	p_queue.push_back(in);
	idx[in.first] = p_queue.size() - 1;
	++p_sz;
	siftup(p_queue.size() - 1);
}
void decrease_key(const pll& in) {
	p_queue[idx[in.first]] = in;
	siftup(idx[in.first]);
}
pll pop(){
	auto ret = p_queue[1];
	p_sz--;

	swap(p_queue[1], p_queue[p_sz]);
	idx[ret.first] = p_sz;

	idx[p_queue[1].first] = 1;
	siftdown(1);
	return ret;
}

long long MAX = numeric_limits<int>::max();

void Dijkstra(int s){
	p_queue.clear();

	p_queue.push_back(make_pair(0, 0));
	p_sz = 1;
	idx.assign(N + 1, 0);

	for(int i = 1; i <= N; ++i){
		if(i != s){
			insert(make_pair(i, MAX));
		} else{
			insert(make_pair(i, 0));
		}
	}

	while(p_sz != 1){
		auto v1 = pop();
		int u = v1.first;
		for(size_t i = 0; i < adj_list[u].size(); ++i){
			auto v2 = adj_list[u][i];
			auto v = v2.first;
			if(idx[v] < p_sz && v1.second + v2.second < dist(idx[v])){
				decrease_key(make_pair(v, v1.second + v2.second));
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
		adj_list.clear();
		cin >> N >> K >> X >> M >> S;
		adj_list.assign(N + 1, {});
		int a, b, c;
		for(int i = 0; i < M; ++i){
			cin >> a >> b >> c;
			adj_list[a].push_back(make_pair(b, c));
			adj_list[b].push_back(make_pair(a, c));
		}
		for(int i = 1; i <= K; ++i){
			for(int j = 1; j <= K; ++j){
				if(i != j){
					adj_list[i].push_back(make_pair(j, X));
				}
			}
		}
		Dijkstra(S);
		for(int i = 1; i <= N; ++i){
			cout << dist(idx[i]) << " ";
		}
		cout << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}