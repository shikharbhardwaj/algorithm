#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstring>

std::vector<int> node[1000001];
int ti[1000001];
bool vis[1000001];

int subtree_sums(int i) {
	vis[i] = 1;
	for(const auto v : node[i]){
		if(!vis[v]){
			ti[i] += subtree_sums(v);
		}
	}
	return ti[i];
}

int x;
int u = 0, v = 0;
bool found = false;

std::pair<int, int> create_solution(int i){
	if(found) {
	}

	vis[i] = 1;
	std::pair<int, int> cur, ret;
	ret = cur = {0, 0};

	if(ti[i] == 2 * x / 3){
		u = i;
	}
	if(ti[i] == x / 3){
		if(u && u != i){
			v = i;
			std::cout << u << " " << v << std::endl;
			exit(0);
		}
		cur.first = i;
	}

	for(const auto v : node[i]){
		if(!vis[v]){
			auto pi = create_solution(v);
			if(pi.first){
				if(!ret.first){
					ret.first = pi.first;
				} else if(!ret.second){
					ret.second = pi.first;
				}
			}
			if(pi.second){
				if(!ret.first){
					ret.first = pi.second;
				} else if(!ret.second){
					ret.second = pi.second;
				}
			}
		}
	}
	if(ti[i] == 2 * x / 3){
		u = 0;
	}
	if(ret.first && ret.second){
		std::cout << ret.first << " " << ret.second << std::endl;
		exit(0);
	}
	return (ret.first) ? ret : cur;
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	std::cin.rdbuf(in.rdbuf());    // save and redirect
	std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	int N, v, root;
	std::cin >> N;
	x = 0;
	for(int i = 1; i <= N; ++i) {
		std::cin >> v >> ti[i];
		x += ti[i];
		if(v != 0){
			node[i].push_back(v);
			node[v].push_back(i);
		} else{
			root = i;
		}
	}

	if(x % 3 == 0){
		subtree_sums(root);
		memset(vis, 0, sizeof(vis));

		create_solution(root);
	}
	std::cout << "-1" << std::endl;
}