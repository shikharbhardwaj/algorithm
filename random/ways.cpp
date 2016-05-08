#include <cstdio>
#include <cstring>
int path[100][100]; //The inputs, with the states of the paths
int nums[100][100]; //The number of possible paths
//Count the number of ways to go from the topmost corner
//to the lowermost
int calls = 0;
int main(int argc, char **argv){
    if(argc > 1){
        int n = 0;
        for(int i = 0; argv[1][i] != '\0' ;i++){
            n += argv[1][i] - '0';
            n *= 10;
        }
        n /= 10;
        printf("%d\n", n);
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    path[i][j] = 1;
                    nums[i][j] = 0;
                }
            }
            if(path[0][0] != 0){
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
                for(int i = 1; i < n; i++){
                    for(int j = 1; j < n; j++){
                        if(path[i][j] == 0){
                            continue;
                        }
                        else{
                            nums[i][j] = nums[i-1][j] + nums[i][j-1];
                        }
                    }
                }
                //Recursion is shit
                if(path[n-1][n-1] == 0){
                    printf("0\n");
                }
                else{
                    printf("%d\n", nums[n-1][n-1]);
                }
            }
    }
}
