#include <cmath>
#include <cstdio>
int Z(int N) {
    // task : find the number of zeroes at the end of N!
    int ret = 0;
    int i = 1, add;
    while ((add = N / pow(5, i))) {
        ret += add;
        i++;
    }
    return ret;
}
int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        printf("%d\n", Z(N));
    }
}
