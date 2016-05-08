#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
int getCorrect(char *correct, char *chef, int N){
    int ret = 0;
    for(int i = 0; i < N; i++){
        if(correct[i] == chef[i]){
            ret++;
        }
    }
    return ret;
}
int main(){
    int T, N, max, reqd;
    scanf("%d", &T);
    char correct[1005], chef[1005];
    std::pair<int, int> costs[1005];
    while(T--){
        scanf("%d", &N);
        std::cin>>correct;
        std::cin>>chef;
        max = getCorrect(correct, chef, N);
        for(int i = 0; i <= N; i++){
            scanf("%d", &costs[i].first);
            costs[i].second = i;
        }
        reqd = costs[N].first;
        if(max != N){
            std::sort(&costs[0], &costs[N+1], std::greater<std::pair<int, int>>());
            for(int i = 0; i <= N; i++){
                if(costs[i].second <= max){
                    printf("%d\n", costs[i].first);
                    break;
                }
            }
        }
        else{
            printf("%d\n", reqd);
        }
    }
    return 0;
}
