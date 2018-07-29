#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

const int num_vertices = 16;
int N, E;

void print_vec(const vi& vec) {
	copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

vi graph[num_vertices];

int capacity[num_vertices][num_vertices], F[num_vertices][num_vertices], res_capacity[num_vertices][num_vertices];

template <typename T>
class queue {
	vector<T> inbox, outbox;
public:
	void enqueue(T in) {
		inbox.emplace_back(in);
	}

	T dequeue() {
		if(outbox.empty()) {
			outbox = move(inbox);
			inbox.clear();
		}
		T val = outbox.back();
		outbox.pop_back();
		return val;
	}
	bool empty() {return inbox.empty() && outbox.empty();}
};

bool bfs(int s, int t, vi& path) {
	vector<int> parent(N, -1);

	queue<int> next;
	next.enqueue(s);

	parent[s] = s;
	bool found = false;
	while(next.empty() == false && !found) {
		int cur = next.dequeue();

		for(auto v : graph[cur]) {

			if(parent[v] == -1) {
				parent[v] = cur;
				if(res_capacity[cur][v] == 0) continue;
				next.enqueue(v);
			}
			if(v == t) {
				found = true;
				break;
			}
		}
	}

	if(found) {
		path.clear();
		int cur = t;
		do {
			path.push_back(cur);
			cur = parent[cur];
		} while(cur != s);
	}

	return found;
}

int floydWarshall(int s, int t) {
	int max_flow = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			F[i][j] = 0;
			res_capacity[i][j] = capacity[i][j];
		}
	}
	vi path;

	while(bfs(s, t, path)) {
		cout << "Found augmenting path : ";
		print_vec(path);
    // Augment flow along the path.
    // Find the minimum res_capacity edge
		int cur, prev, limit = std::numeric_limits<int>::max();
		for(auto it = path.rbegin(); it != path.rend(); ++it) {
			cur = *it;
			if(cur == t) { prev = t; continue; }
			limit = min(limit, res_capacity[cur][prev]);
			prev = cur;
		}
		max_flow += limit;

		for(auto it = path.rbegin(); it != path.rend(); ++it) {
			cur = *it;
			if(cur == t) { prev = t; continue; }
			F[cur][prev] += limit;
			res_capacity[cur][prev] -= limit;
			prev = cur;
		}
	}

	return max_flow;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	  // Let's implement Floyd-Warshall
	cin >> N >> E;
	int u, v, c;
	for(int i = 0; i < E; ++i) {
		cin >> u >> v >> c;
		graph[u].push_back(v);
		capacity[u][v] = c;
	}
	cout << endl;
	cout << floydWarshall(0, 5) << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
