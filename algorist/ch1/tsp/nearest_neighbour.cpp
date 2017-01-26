#include <iostream>
#include <prettyprint/prettyprint.hpp>
#include <set>
#include <vector>

using point = std::pair<float, float>;
float dist(point p1, point p2) {
    return sqrt(float((p1.first - p2.first) * (p1.first - p2.first) +
                      (p1.second - p2.second) * (p1.second - p2.second)));
}
std::vector<std::pair<float, float>> points;
std::vector<int> path;
std::set<int> visited;
void dfs(size_t cur) {
    if (visited.find(cur) != visited.end())
        return;
    visited.insert(cur);
    float min_dist = 1e9;
    size_t min_node = cur;
    for (size_t i = 0; i < points.size(); i++) {
        if (visited.find(i) == visited.end()) {
            auto next_dist = dist(points[i], points[cur]);
            if (next_dist < min_dist) {
                min_dist = next_dist;
                min_node = i;
            }
        }
    }
    if (min_node == cur)
        return;
    path.push_back(min_node);
    dfs(min_node);
}
int main() {
    if (!std::freopen("nearest.in", "r", stdin)) {
        return 1;
    }
    size_t N;
    std::cin >> N;
    points.resize(N);
    for (size_t i = 0; i < N; ++i) {
        std::cin >> points[i].first >> points[i].second;
    }
    path.push_back(0);
    dfs(0);
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
