#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

void dfs_visit(int cur, std::vector<std::vector<int>> &adj, std::vector<bool> &visited, std::vector<int> &order){
	order.push_back(cur);
	visited[cur] = true;
	for(size_t i = 1; i < adj[cur].size(); ++i){
		if(!visited[adj[cur][i]]){
			dfs_visit(adj[cur][i], adj, visited, order);
		}
	}
}
void dfs(int cur, std::vector<std::vector<int>> &adj){
	std::vector<bool> visited(adj.size(), false);
	std::vector<int> dfs_order;
	dfs_visit(cur, adj, visited, dfs_order);
	for(auto elem : dfs_order){
		std::cout << elem << " ";
	}
	std::cout << "\n";
}

void bfs(int src, std::vector<std::vector<int>> &adj) {
	std::vector<bool> visited(adj.size(), false);
	std::vector<int> visit_order;
	std::vector<int> frontier = {src};
	std::vector<int> next;
	visited[src] = true;
	while(!frontier.empty()){
		for(int i = frontier.size() - 1; i >= 0; --i){
			int cur = frontier[i];
			visit_order.push_back(cur);
			for(size_t j = 1; j < adj[cur].size(); ++j){
				if(!visited[adj[cur][j]]){
					next.push_back(adj[cur][j]);
					visited[adj[cur][j]] = true;
				}
			}
			frontier.pop_back();
		}
		frontier = next;
		std::reverse(frontier.begin(), frontier.end());
		next.clear();
	}
	for(auto elem : visit_order){
		std::cout << elem << " ";
	}
	std::cout << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	int t;
	std::cin >> t;
	for(int g = 1; g <= t; ++g) {
		int n;
		std::cin >> n;
		std::vector<std::vector<int>> adj(n + 1);
		for(int i = 1; i <= n; ++i){
			int t, m;
			std::cin >> t >> m;
			adj[i].assign(m + 1, {});
			for(int j = 1; j <= m; ++j){
				std::cin >> adj[t][j];
			}
		}
		std::cout << "graph " << g << std::endl;
		int v, i;
		while(true){
			std::cin >> v >> i;
			if(v == 0 && i == 0){
				break;
			}
			if(i == 0){
				dfs(v, adj);
			} else{
				bfs(v, adj);
			}
		}
	}
#ifndef ONLINE_JUDGE
	std::cin.rdbuf(cinbuf);
	std::cout.rdbuf(coutbuf);
#endif	
}
