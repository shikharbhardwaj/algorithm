#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

typedef std::pair<int, int> pii;

int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--) {
        int N, U, V, P;
        std::cin >> N;
        std::unordered_map<int, std::vector<int>> adj_list;
        std::map<int, int> pop;
        std::map<int, int> ids;

        for (int i = 0; i < N; i++) {
            std::cin >> P;
            pop[i + 1] = P;
            ids[P] = i + 1;
        }
        for (int i = 0; i < N - 1; i++) {
            std::cin >> U >> V;
            if (adj_list.find(U) == adj_list.end()) {
                adj_list[U] = {V};
            } else {
                adj_list[U].push_back(V);
            }
            if (adj_list.find(V) == adj_list.end()) {
                adj_list[V] = {U};
            } else {
                adj_list[V].push_back(U);
            }
        }
        std::vector<pii> deleted;
        for (int i = 1; i <= N; i++) {
            deleted.emplace_back(i, pop[i]);
            ids.erase(pop[i]);
            if (adj_list[i].size() == (size_t)N - 1) {
                std::cout << "0 ";
            } else {
                for (auto elem : adj_list[i]) {
                    deleted.emplace_back(elem, pop[elem]);
                    ids.erase(pop[elem]);
                }
                std::cout << ids.rbegin()->second << " ";
            }
            for (auto elem : deleted) {
                ids[elem.second] = elem.first;
            }
            deleted.clear();
        }
        std::cout << "\n";
    }
}
