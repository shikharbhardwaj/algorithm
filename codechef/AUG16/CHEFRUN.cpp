// Perform a DFS on this directed graph
#include <iostream>
#include <map>
#include <vector>
#define getchar getchar_unlocked
int readInt() {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9')
            break;
        ch = getchar();
    }
    if (ch == '-')
        minus = true;
    else
        result = ch - '0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9')
            break;
        result = result * 10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}
int main() {
    int T;
    T = readInt();
    while (T--) {
        int n, temp;
        n = readInt();
        std::vector<int> id(n);
        std::vector<int> status(n, -1);
        for (int i = 0; i < n; i++) {
            temp = readInt();
            // The index of the next node
            id[i] = i + temp + 1;
            id[i] %= n;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (status[i] != -1) {
                // This is isolated or already part of a cycle
                continue;
            }
            int cur = i;
            std::map<int, bool> visited;
            do {
                visited[cur] = true;
                cur = id[cur];
            } while (visited[cur] == false && status[cur] == -1);
            if (cur == i) {
                // The currently visited nodes form a cycle
                for (const auto &elem : visited) {
                    status[elem.first] = i;
                }
            } else {
                status[i] = -2; // This is an isolated component, without cycle
            }
        }
        for (int i = 0; i < n; i++) {
            if (status[i] != -2) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}
