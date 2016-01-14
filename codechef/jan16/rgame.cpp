#include <iostream>
int nums[10001], left[10001], right[10001], sums[10001];
int N;
//Approach : Backtrack to find each possibility and compute the answer
//
//At every position in the array, we have two choices, either to go left
//or right. As this is not an optimization problem, we need to keep states
//for each subproblem tree. Maintain two more arrays, left and right, which 
//give the state of the left and right ends of the number sequence at the 
//current state.
int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    std::cin>>T;
    while(T--){
        int left, right;
        std::cin>>N;
        for(int i = 0; i <= N; i++){
            std::cin>>nums[i];
        }
        left = right = nums[0];
    }
}
