#include <iostream>
#include <random>
#include <limits>
#include <vector>
const int test_size = 10000;
int max_sum(const std::vector<int> array, int left, int right, int &maxLeft, int &maxRight){
    if(left < right){
        return 0;
    }
    int mid = (left+right)/2;
    int maxSum = 
}
int main(){
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    std::vector<int> array;
    for(int i = 0 ; i < 100000; i++){
        array.push_back(dist(e2));
    }
    //Find the maximum subarray in this array
    
}
