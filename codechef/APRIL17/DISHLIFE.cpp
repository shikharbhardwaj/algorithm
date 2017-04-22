#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--) using ll = long long;
using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using namespace std;

struct union_find{
	std::vector<size_t> parent;
	std::vector<int> rank;

	union_find(){
		parent.push_back(0);
		rank.push_back(0);
	}

	size_t find(size_t x){
		if(parent[x] == x){
			return x;
		}
		else{
			// Do some path compression
			parent[x] = find(parent[x]);
			return parent[x];
		}
	}
	bool connected(size_t x, size_t y){
		return find(x) == find(y);
	}
	void insert(){
		parent.push_back(parent.size());
	}
	void join(size_t x, size_t y){
		size_t x_root = find(x);
		size_t y_root = find(y);
		if(x_root == y_root){
			return;
		}
		else{
			if(rank[x_root] == rank[y_root]){
				parent[y_root] = parent[x_root];
				rank[y_root] += 1;
			}
			else if(rank[x_root] > rank[y_root]){
				parent[y_root] = x_root;
			}
			else{
				parent[x_root] = y_root;
			}
		}
	}
};

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	int T;
	cin >> T;
	while(T--){
		int N, K, P, t;
		cin >> N >> K;
		vector<int> visited(K + 1, 0);
		vector<vector<int>> isls(N);
		for(int i = 0; i < N; ++i){
			cin >> P;
			isls[i].assign(P, 0);
			for(int j = 0; j < P; ++j){
				cin >> isls[i][j];
				visited[isls[i][j]] += 1;
			}
		}
		bool redundant = false;
		for(int i = 0; i < N; ++i){
			int cnt = 0;
			for(size_t j = 0; j < isls[i].size(); ++j){
				if(visited[isls[i][j]] > 1){
					cnt++;
				}
			}
			if(cnt == isls[i].size()){
				redundant = true;
				break;
			}
		}
		bool connected = true;
		for(int i = 1; i <= K; ++i){
			if(visited[i] == 0){
				connected = false;
				break;
			}
		}
		if(!connected){
			cout << "sad";
		} else if(connected && redundant){
			cout << "some";
		} else{
			cout << "all";
		}
		cout << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}