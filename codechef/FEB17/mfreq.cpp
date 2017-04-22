#include <algorithm>
#include <iomanip>
#include <fstream>
#include <iostream>

typedef struct node {
	int l, r;
	int val, k;
	int l_b, r_b;
	std::pair<int, int> lend;
	std::pair<int, int> rend;
} node, interval;

node tree[262144];
int size;

int tree_size(int N) {
	if (!(N & (N - 1))) {
		return 2 * N;
	}
	int ret = 1;
	while (N) {
		N >>= 1;
		ret <<= 1;
	}
	return ret << 1;
}
void combine(node &left_child, node &right_child, node &cur){
	cur.l = left_child.l;
	cur.r = right_child.r;
	if(left_child.val < 0){
		cur.val = -1;
		cur.k = 0;
		cur.lend = {-1, cur.r - cur.l + 1};
		cur.rend = {-1, cur.r - cur.l + 1};
		return;
	} else{
		if(right_child.val < 0){
			cur.val = left_child.val;
			cur.k = left_child.k;
			cur.l_b = left_child.l_b;
			cur.r_b = left_child.r_b;
			cur.lend = left_child.lend;
			cur.rend = {-1, right_child.r - right_child.l + 1};
			return;
		}
	}
	if (left_child.rend.first != right_child.lend.first) {
		cur.val =
		(left_child.k >= right_child.k) ? left_child.val : right_child.val;
		cur.k = std::max(left_child.k, right_child.k);
		cur.l_b =
		(left_child.k >= right_child.k) ? left_child.l_b : right_child.l_b;
		cur.r_b =
		(left_child.k >= right_child.k) ? left_child.r_b : right_child.r_b;
		cur.lend = left_child.lend;
		cur.rend = right_child.rend;
	} else {
		if(left_child.rend.second + right_child.lend.second > std::max(left_child.k, right_child.k)){
			cur.k = left_child.rend.second + right_child.lend.second;
			cur.val = left_child.rend.first;
			cur.l_b = left_child.r - left_child.rend.second + 1;
			cur.r_b = right_child.l + right_child.lend.second - 1;
		} else{
			cur.val =
			(left_child.k >= right_child.k) ? left_child.val : right_child.val;
			cur.k = std::max(left_child.k, right_child.k);
			cur.l_b =
			(left_child.k >= right_child.k) ? left_child.l_b : right_child.l_b;
			cur.r_b =
			(left_child.k >= right_child.k) ? left_child.r_b : right_child.r_b;
		}
		// Check if the ends have changed
		if(left_child.lend.second == left_child.r - left_child.l + 1){
			cur.lend = {left_child.lend.first, left_child.lend.second + right_child.lend.second};
		} else{
			cur.lend = left_child.lend;
		}
		if(right_child.rend.second == right_child.r - right_child.l + 1){
			cur.rend = {right_child.rend.first, right_child.rend.second + left_child.rend.second};
		} else{
			cur.rend = left_child.rend;
		}
	}
}
void update_info(int id) {
	auto &cur = tree[id];
	auto &left_child = tree[2 * id];
	auto &right_child = tree[2 * id + 1];
	combine(left_child, right_child, cur);
}

void init_segtree(std::vector<int> &ar) {
	size = tree_size(ar.size());
	int N = size / 2;
	for (size_t i = 0; i < ar.size(); ++i) {
		tree[i + N].l = tree[i + N].r = i + 1;
		tree[i + N].val = ar[i];
		tree[i + N].k = 1;
		tree[i + N].l_b = tree[i + N].r_b = i + 1;
		tree[i + N].lend = {ar[i], 1};
		tree[i + N].rend = {ar[i], 1};
	}
	for (int i = ar.size(); i < size; ++i) {
		tree[i + N].l = tree[i + N].r = i + 1;
		tree[i + N].val = -1;
		tree[i + N].k = 0;
		tree[i + N].l_b = tree[i + N].r_b = i + 1;
		tree[i + N].lend = {-1, 0};
		tree[i + N].rend = {-1, 0};
	}
	for (int i = N - 1; i > 0; --i) {
		update_info(i);
	}
}
void node_str(node &cur){
		std::cout << "["<< cur.l << ", " << cur.r << "] :: " << cur.val << ", " << cur.k << " | "<< "->(" << cur.l_b << ", " << cur.r_b << ")";
		std::cout << " \t{"<< cur.lend.first << ", " << cur.lend.second << "}"  << " {" << cur.rend.first << ", " << cur.rend.second << "}";
		std::cout << std::endl;
}
void dump(){
	int i = 1;
	while(i != size){
		node_str(tree[i]);
		i++;
	}
}
void query(int i, int L, int R, node &ans){
	auto &cur = tree[i];
	if(i >= size){
		return;
	}
	if(cur.l > R || cur.r < L){
		return;
	}
	else if(cur.l >= L && cur.r <= R){
		if(ans.val < 0){
			auto cpy = tree[i];
			ans = cpy;
		} else{
			if(ans.l > cur.r){
				combine(cur, ans, ans);
			} else{
				combine(ans, cur, ans);
			}
		}
	}
	else{
		query(2 * i, L, R, ans);
		query(2 * i + 1, L, R, ans);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("large.in");
	std::ofstream out("out.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif
  int N, Q;
  int L, R, k;
  std::cin >> N >> Q;
  std::vector<int> ar(N);
  for (auto &e : ar) {
  	std::cin >> e;
  }
  init_segtree(ar);
  while (Q--) {
  	std::cin >> L >> R >> k;
  	node ans;
  	ans.val = -1;
  	query(1, L, R, ans);
  	if(ans.k < k){
  		std::cout << "-1" << std::endl;
  	} else{
  		std::cout << ans.val << std::endl;
  	}
  }
}