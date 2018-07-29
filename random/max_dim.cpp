#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
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

typedef struct node {
	int left, right;
	int min;
} node, interval;

node tree[262144];
int size;

size_t get_size(size_t n) {
	return 1 << size_t(ceil(log2(n)) + 1);
}

void build_segtree(const vector<int>& ar) {
	size = get_size(ar.size());

	// Fill the leaves first.
	int start_leaf = size / 2;
	for(int i = 0; i < ar.size(); ++i) {
		tree[start_leaf + i].left = tree[start_leaf + i].right = i + 1;
		tree[start_leaf + i].min = ar[i];
	}
	// Fill the remaining leaves with invalid data.
	for(int i = start_leaf + ar.size(); i < size; ++i) {
		tree[i].left = tree[i].right = i + 1 - start_leaf;
		tree[i].min = 1e9 + 1;
	}

	// Combine lower nodes to construct the tree.
	for(int i = start_leaf - 1; i > 0; --i) {
		int left = 2 * i;
		int right = left + 1;
		tree[i].left = tree[left].left;
		tree[i].right = tree[right].right;
		tree[i].min = min(tree[left].min, tree[right].min);
	}
}

void query(int i, int left, int right, int& ans) {
	if(i >= size)
		return;
	auto& cur = tree[i];
	if(cur.left > right || cur.right < left) {
		return;
	}
	if(cur.left >= left && cur.right <= right) {
		// This is part of the solution.
		ans = min(ans, cur.min);
	} else {
		query(2 * i, left, right, ans);
		query(2 * i + 1, left, right, ans);
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
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		int N, Q;
		cin >> N >> Q;
		vector<int> ar(N);
		for(auto& e : ar)
			cin >> e;

		build_segtree(ar);
		int L, R, ans;
		cout << "Scenario #" << i << ":" << endl;

		while(Q--) {
			ans = 1e9 + 1;
			cin >> L >> R;
			query(1, L, R, ans);

			cout << ans << endl;
		}
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
