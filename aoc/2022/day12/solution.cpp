#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)
#define ALL(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;


using namespace std;

struct Position {
    int x, y;

    Position(int x_, int y_) : x(x_), y(y_) {}

    Position operator+(const Position& other) const {
        return Position(x + other.x, y + other.y);
    }

    bool operator==(const Position& other)  const {
        return x == other.x && y == other.y;
    }

    bool operator<(const Position& other) const {
        if (x != other.x) return x < other.x;

        return y < other.y;
    }
};

ostream& operator<<(ostream& os, const Position& pos) {
    return os << "(" << pos.x << ", " << pos.y << ")";
}

struct Grid {
    vector<string> grid_data;

    Grid(vector<string> grid_data_) : grid_data(grid_data_) {}

    char get(const Position& pos) {
        if (grid_data[pos.x][pos.y] == 'S') return 'a';
        if (grid_data[pos.x][pos.y] == 'E') return 'z';

        return grid_data[pos.x][pos.y];
    }

    bool valid(const Position& pos) {
        return pos.x >= 0 && pos.x < grid_data.size() && pos.y >= 0 && pos.y <
            grid_data[0].size();
    }

    vector<Position> get_viable_neighbours(const Position& cur_position) {
        vector<Position> viable_neighbours;
        const vector<Position> dxy = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for (auto d : dxy) {
            auto new_position = cur_position + d;
            if (valid(new_position) && (get(new_position) - get(cur_position) <= 1)) {
                viable_neighbours.emplace_back(new_position);
            }
        }

        return viable_neighbours;
    }

    Position get_position(char ch) {
        for (int i = 0; i < grid_data.size(); ++i) {
            for (int j = 0; j < grid_data[0].size(); ++j) {
                if (grid_data[i][j] == ch) return Position(i, j);
            }
        }
    }

    int bfs(const Position& start) {
        Position end_pos = get_position('E');

        cout << "Start: " << start << endl;
        cout << "End: " << end_pos << endl;

        vector<pair<Position, Position>> frontier = {{start, start}}, next;
        set<Position> visited = {start};
        int dist = 0;

        while (!frontier.empty()) {
            auto [parent, cur] = frontier.back();
            frontier.pop_back();

            if (cur == end_pos) {
                return dist;
            }

            for (auto nei : get_viable_neighbours(cur)) {
                if (nei == parent) continue;
                if (visited.count(nei)) continue;

                visited.insert(nei);
                next.push_back(make_pair(cur, nei));
            }

            if (frontier.empty()) {
                ++dist;
                frontier = move(next);
                next.clear();
            }
        }

        throw std::logic_error("Could not find a path to the end position");
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in2.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif
    // Code
    int num_lines; cin >> num_lines;

    vector<string> input(num_lines);
    for (auto& e : input) cin >> e;

    Grid grid(input);

    vector<Position> starts;

    for (int i = 0; i < input.size(); ++i) {
        for (int j = 0; j < input[0].size(); ++j) {
            if (input[i][j] == 'a' || input[i][j] == 'S') starts.emplace_back(i, j);
        }
    }

    int min_so_far = input[0].size() * input.size();

    for (auto start : starts) {
        try {
            min_so_far = min(min_so_far, grid.bfs(start));
        } catch(std::logic_error e) {
            cout << "Could not find a path from: " << start << endl;
        }
    }

    cout << min_so_far << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}