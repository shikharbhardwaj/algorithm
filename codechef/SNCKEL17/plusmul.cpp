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

struct node {
	int l, r;
	ll lend, rend, ans;
};
vector<node> tree;

ll eval(int id, ll s1, ll rf, ll ls, ll s2) {}

void combine(size_t i){
	auto &cur = tree[i];
	auto &l_child = tree[2 * i];
	auto &r_child = tree[2 * i + 1];
	cur.l = l_child.l;
	cur.r = r_child.r;
	cur.lend = l_child.lend;
	cur.rend = r_child.rend;
	ll s1 = (l_child.ans - l_child.rend) / (l_child.rend + 1); // Mod inv much!
	ll s2 = (r_child.ans - r_child.lend) / (r_child.rend + 1);
	for(int i = 0; i < 8; ++i){
		cur.ans += (combine(i, s1, l_child.rend, r_child.lend, s2)) % mod;
	}
}
void init_seg(const vi &ar){
	int N = 1 << int(ceil(log2(ar.size())));
	tree.resize(2 * N);
	for(size_t i = 0; i < ar.size(); ++i){
		tree[i + N].l = tree[i + N].r = i;
		tree[i + N].lend = tree[i + N].rend = tree[i + N].ans = ar[i];
	}
	for(int i = N + ar.size(); i < 2 * N; ++i){
		tree[i].l = tree[i].r = i = N;
	}
	for(int i = N - 1; i > 0; --i){
		combine(i);
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
	init_seg({1, 2, 3});
	TEST{
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
