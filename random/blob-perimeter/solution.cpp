#include <bits/stdc++.h>

// #define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define FOR1(i, n) for(int i = 1; i <= n; ++i)
#define TEST int T; std::cin >> T; while(T--)
#define CASE int C; std::cin >> C; FOR1(case_num, C)
#define ALL(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using namespace std;


struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }
};

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif     
    int x, y;
    cin >> x >> y;
    swap(x, y);
    vector<string> grid;
    
    string line;
    while (cin >> line) {
        grid.emplace_back(line);
    }

    int n = grid.size(), m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m));

    auto valid = [&](int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    int ans = 0;

    function<void(int, int)> visit = [&](int i, int j) {
        visited[i][j] = true;
        int cur_color = grid[i][j];

        Point cur_point{i, j};
        const vector<Point> dxy = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (auto d : dxy) {
            auto next_point = cur_point + d;

            if (valid(next_point.x, next_point.y) && grid[next_point.x][next_point.y] == cur_color) {
                if (!visited[next_point.x][next_point.y]) visit(next_point.x, next_point.y);
            } else {
                ++ans;
            }
        }
    };

    visit(x, y);

    cout << ans << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}