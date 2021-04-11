#include <bits/stdc++.h>


using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "[";

    for (auto it = begin(vec); it != end(vec);) {
        os << *it;
        ++it;

        if (it != end(vec)) {
            os << ", ";
        }
    }

    os << "]";

    return os;
}

int solve(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    vector<pair<int, int>> nodes;
    map<pair<int, int>, int> idx_map;

    auto valid = [&](int i, int j) {
        return i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size();
    };

    for (int i = 0;  i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] != 0) {
                idx_map[make_pair(i, j)] = nodes.size();
                nodes.emplace_back(i, j);
            }
        }
    }

    int n = nodes.size();

    // cout << n << endl;

    int mask_size = 1 << n;

    // dp[mask][i] = max possible visiting mask nodes ending at i.

    vector<vector<int>> dp(mask_size, vector<int>(n));

    for (int mask = 1; mask < mask_size; ++mask) {
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0) continue;

            auto [cx, cy] = nodes[i];

            dp[mask][i] = matrix[cx][cy];

            vector<pair<int, int>> dxy = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

            for (auto [dx, dy] : dxy) {
                int nx = cx + dx, ny = cy + dy;

                if (valid(nx, ny) && idx_map.find({nx, ny}) != idx_map.end()) {
                    int j = idx_map[{nx, ny}];

                    if (((1 << j) & mask) == 0) continue;

                    dp[mask][i] = max(dp[mask][i], dp[mask - (1 << i)][j] + matrix[cx][cy]);
                }
            }
        }
    }

    // for (auto e : dp)
    //     cout << e << endl;

    return *max_element(begin(dp.back()), end(dp.back()));
}

int dfs(int, int, vector<vector<int>>);

int solve2(vector<vector<int>>& mat) {
    if (mat.empty()) return 0;
    if (mat[0].empty()) return 0;

    int n = mat.size(), m = mat[0].size();

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] != 0) ans = max(ans, dfs(i, j, mat));
        }
    }

    return ans;
}

int dfs(int i, int j, vector<vector<int>> mat) {
    if (mat[i][j] == 0) return 0;
    int cur_val = mat[i][j];
    mat[i][j] = 0;

    int ans = cur_val;

    vector<pair<int, int>> dxy = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    auto valid = [&](int i, int j) {
        return i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size();
    };

    for (auto [dx, dy] : dxy) {
        int nx = i + dx, ny = j + dy;
        if (!valid(nx, ny)) continue;

        ans = max(ans, cur_val + dfs(nx, ny, mat));
    }

    return ans;
}

int main() {
    vector<vector<int>> input = {
        {1, 5, 3, 3},
        {3, 4, 2, 4},
        {4, 4, 3, 2},
        {4, 2, 2, 4},
        {4, 5, 2, 2}};


    vector<vector<int>> input2 = {
        {1, 0, 5, 5, 3},
        {3, 0, 4, 0, 4},
        {4, 0, 3, 0, 2},
        {4, 0, 2, 0, 4},
        {4, 5, 1, 3, 2}};

    {
        auto t0 = chrono::steady_clock::now();
        cout << solve(input2) << endl;
        auto t1 = chrono::steady_clock::now();

        cout << "Time taken: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << endl;
    }

    {
        auto t0 = chrono::steady_clock::now();
        cout << solve2(input2) << endl;
        auto t1 = chrono::steady_clock::now();

        cout << "Time taken: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << endl;
    }
}