#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int a[750001], dp[750001], id[750001], visited[750001];

int main() {
    short t;
    int n, i, j;
    long sum = 0;
    cin >> t;
    while (t--) {
        cin >> n;
        sum = 0;
        memset(visited, 0, sizeof(int) * n);
        for (i = 0; i < n; ++i) {
            cin >> a[i];
            visited[a[i]]++;
            dp[i] = 0;
        }
        dp[n - 1] = 1;
        sort(a, a + n);
        for (i = 0; i < n; i++) {
            id[a[i]] = i;
        }
        int max = a[n - 1];
        for (i = n - 2; i >= 0; i--) {
            for (j = 2; j * a[i] <= max; j++) {
                if (visited[j * a[i]] == 1)
                    dp[i] += dp[id[j * a[i]]];
            }
            dp[i]++;
        }
        for (i = 0; i < n; i++)
            sum += dp[i];
        cout << sum << endl;
    }
    return 0;
}
