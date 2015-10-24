#include <cstdio>
int count[1000001];
int main(){
    int t,temp, max, min;
    scanf("%d", &t);
    scanf("%d", &max);
    min = max;
    count[max]++;
    t--;
    while(t--){
        scanf("%d", &temp);
        if(temp > max){
            max = temp;
        }
        else if(temp < min){
            min = temp;
        }
        count[temp]++;
    }
    for(int i = min; i <= max; i++){
        while(count[i]--){
            printf("%d\n", i);
        }
    }
}
