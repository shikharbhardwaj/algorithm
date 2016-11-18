#include <iostream>
#include <list>
#include <map>
#include <vector>
// Implement an undirected graph
std::map<int, std::vector<int>> adj_list;
void add_node(int id) { adj_list[id]; }
void add_edge(int id1, int id2) {
    adj_list[id1].push_back(id2);
    adj_list[id2].push_back(id1);
}
int degree(int id) { return adj_list[id].size(); }
int main() {}
