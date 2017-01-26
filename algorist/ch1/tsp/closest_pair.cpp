#include <cmath>
#include <iostream>
#include <prettyprint/prettyprint.hpp>
#include <unordered_map>
#include <vector>

using point = std::pair<float, float>;

float dist(point p1, point p2) {
    return sqrt(float((p1.first - p2.first) * (p1.first - p2.first) +
                      (p1.second - p2.second) * (p1.second - p2.second)));
}
int main() {
    if (!std::freopen("closest.in", "r", stdin)) {
        return 1;
    }
    int N;
    std::cin >> N;
    std::unordered_map<int, std::vector<int>> vertex_chains;
    std::vector<point> points(N);
    for (int i = 0; i < N; i++) {
        std::cin >> points[i].first >> points[i].second;
        vertex_chains[i] = {i};
    }
    std::set<int> removed;
    for (int i = 1; i < N; i++) {
        float d = 1e9;
        int sm = -1, tm = -1;
        for (auto chain1 : vertex_chains) {
            if (removed.find(chain1.first) != removed.end())
                continue;
            for (auto chain2 : vertex_chains) {
                if (removed.find(chain2.first) != removed.end())
                    continue;
                if (chain1.first == chain2.first)
                    continue;
                std::vector<int> end1 = {chain1.second.back(),
                                         chain1.second.front()};
                std::vector<int> end2 = {chain2.second.back(),
                                         chain2.second.front()};
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        auto cur_dist = dist(points[end1[i]], points[end2[j]]);
                        if (cur_dist < d) {
                            d = cur_dist;
                            sm = end1[i];
                            tm = end2[j];
                        }
                    }
                }
            }
        }
        // Connect sm and tm
        if (sm == vertex_chains[sm].front()) {
            if (tm == vertex_chains[tm].front()) {
                vertex_chains[sm].insert(vertex_chains[sm].begin(),
                                         vertex_chains[tm].rbegin(),
                                         vertex_chains[tm].rend());
            } else {
                vertex_chains[sm].insert(vertex_chains[sm].begin(),
                                         vertex_chains[tm].begin(),
                                         vertex_chains[tm].end());
            }
            removed.insert(tm);
        } else {
            if (tm == vertex_chains[tm].front()) {
                vertex_chains[sm].insert(vertex_chains[sm].end(),
                                         vertex_chains[tm].begin(),
                                         vertex_chains[tm].end());
            } else {
                vertex_chains[sm].insert(vertex_chains[sm].end(),
                                         vertex_chains[tm].rbegin(),
                                         vertex_chains[tm].rend());
            }
        }
        removed.insert(tm);
    }
    std::vector<int> path;
    for (int i = 0; i < N; i++) {
        if (removed.find(i) == removed.end()) {
            path = vertex_chains[i];
            break;
        }
    }
    std::cout << "The min path : ";
    float total_dist = 0;
    std::cout << points[path[0]] << "->";
    for (size_t i = 1; i < path.size(); i++) {
        std::cout << points[path[i]] << "->";
        total_dist += dist(points[i - 1], points[i]);
    }
    std::cout << points[path[0]];
    total_dist += dist(points[path.back()], points[0]);
    std::cout << "\nDistance : " << total_dist << std::endl;
}
