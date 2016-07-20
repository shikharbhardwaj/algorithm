#include <stdio.h>
int main(){
    int T, N, tid, tval, sumid, sums, i;
    scanf("%d", &T);
    while(T--){
        sums = 0;
        sumid = 0;
        scanf("%d", &N);
        for( i = 0;i < N; i++){
            scanf("%d%d", &tid, &tval);
            sums += tval;
            sumid += tid;
        }
        printf("%d\n", sumid - sums);
    }
}
