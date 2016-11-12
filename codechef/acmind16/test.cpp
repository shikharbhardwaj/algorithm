#include <iostream>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m, d, D;
        scanf("%d %d %d %d", &n, &m, &d, &D);

        if (m < n * d || m > n * D || m > n * n) {
            printf("-1\n");
            continue;
        }

        int counter = 0;

        for (int i = 0;; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d %d\n", j, (j + i - 1) % n + 1);
                counter++;
                if (counter >= m)
                    break;
            }

            if (counter >= m)
                break;
        }
    }
}
