#include <cstdio>
#include <cmath>
void normalize(float &in){
    while(in > 360){
        in -= 360;
    }
}
void printTimes(float theta){
    float req = 0;
    for(int i = 0;i < 12; i++){
        for(int j = 0; j < 60; j++){
            req = fabs(0.5*(60*i - 11*j));
            normalize(req);
            if( fabs(req - theta) < 0.00833333333 || fabs(req - 360 + theta) < 0.00833333333){
                if( i < 10 || j < 10 ){
                    if(i < 10 && j < 10){
                        printf("0%d:0%d", i, j);
                    }
                    else if( i < 10 ){
                        printf("0%d:%d", i, j);
                    }
                    else if( j < 10 ){
                        printf("%d:0%d", i, j);
                    }
                }
                else{
                    printf("%d:%d", i, j);
                }
                printf("\n");
            }
        }
    }
}
int main(){
    int T;
    float theta;
    scanf("%d", &T);
    while(T--){
        scanf("%f", &theta);
        if((int)(round(theta*10))%5 == 0){
            printTimes(theta);
        }
    }
}
