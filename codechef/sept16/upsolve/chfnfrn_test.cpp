// include "testlib.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iostream>
#include <map>
#include <math.h>
#include <memory.h>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

using namespace std;

const int maxn = 1e3 + 7;

int n;
bool mt[maxn][maxn];
int color[maxn];

bool dfs(int v, int cl) {
    color[v] = cl;

    for (int to = 1; to <= n; ++to)
        if (to != v && mt[v][to]) {
            if (color[to] == 0)
                if (!dfs(to, 3 - cl))
                    return 0;

            if (color[to] != 3 - color[v])
                return 0;
        }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t-- > 0) {
        int m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                mt[i][j] = 1;

        int a, b;
        while (m-- > 0) {
            cin >> a >> b;
            mt[a][b] = mt[b][a] = 0;
        }

        memset(color, 0, sizeof color);

        bool good = 1;
        for (int i = 1; i <= n; ++i)
            if (color[i] == 0)
                if (!dfs(i, 1))
                    good = 0;

        if (good)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
