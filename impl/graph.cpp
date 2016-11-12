#include <iostream>
#include <list>
#include <map>
#include <vector>
typedef struct node { int id = 0; } node;
std::map<int, std::list<node>> adj_list;
void add_node(int id) { adj_list[id]; }
void add_edge(int id1, int id2);
int main() {}
