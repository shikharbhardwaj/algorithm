#include <cstdio>
int path[100][100]; //The inputs, with the states of the paths
int nums[100][100]; //The number of possible paths
//Count the number of ways to go from the topmost corner
//to the lowermost
void countWays(int i, int j, int n){
    if(i >= n){
        return;
    }
    if(j >= n){
        return;
    }
    printf("The current cell : %d, %d\n", i, j);
    if(path[i-1][j] != 0){
        nums[i][j] = nums[i-1][j];
    }
    if(path[i][j-1] != 0){
        nums[i][j] += nums[i][j-1];
    }
    if(path[i][j] != 0){
        countWays(i+1, j, n);
        countWays(i, j+1, n);
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                scanf("%d", &path[i][j]);
                nums[i][j] = 0;
            }
        }
        if(path[0][0] != 0){    //The entrance is not blocked
            for(int i = 0;i<n;i++){
                if(path[i][0] != 0){
                    nums[i][0] = 1;
                }
                else{   //Break if we encounter a blocked cell
                    break;
                }
            }
            for(int i = 0;i<n;i++){
                if(path[0][i] != 0){
                    nums[0][i] = 1;
                }
                else{   //Break if we encounter a blocked cell
                    break;    
                }
            }
            countWays(1,1,n);
            if(path[n-1][n-1] == 0){    //If we did not reach the desitination
                printf("0\n");
            }
            else{
                printf("%d\n", nums[n-1][n-1]);
            }
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    printf("%d : ", nums[i][j]);
                }
                printf("\n");
            }
        }
    }
}
