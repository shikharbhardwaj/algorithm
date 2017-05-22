#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

std::unordered_map<int, std::list<int>> adj_list;

void insert_edge(int u, int v){
	if(adj_list.find(u) == adj_list.end()){
		adj_list[u] = {v};
	} else{
		adj_list[u].push_back(v);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("large.in");
	std::ofstream out("out.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	

	int n;
	std::cin >> n;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		std::cin >> u >> v;
		insert_edge(u, v);
		insert_edge(v, u);
	}
}
