#include <iostream>
#include <cassert>
#include <algorithm>
#include <random>
#include <vector>
#include <limits>
std::random_device rng;
std::mt19937 gen(rng());
std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
template <typename iter, 
         typename T = typename std::iterator_traits<iter>::value_type, 
         typename comp = typename std::less<T>>
     void merge(iter begin, iter mid, iter end){
        //Merge the ranges pointed by [begin, mid] and [mid+1, end)
        //Number of elements in range[begin, mid] : mid - begin + 1
        //Number of elements in range[mid+1, end) : end - mid - 1
         if(*mid <= *(mid+1)){
             return;
         }
         std::vector<T> left(mid - begin + 1);
         std::vector<T> right(end - mid - 1);
         for(iter i = begin; i <= mid; i++){
             left[i-begin] = *i;
         }
         for(iter i = mid + 1; i < end; i++){
             right[i-mid-1] = *i;
         }
         iter li, ri, oi;
         li = left.begin();
         ri = right.begin();
         for(oi = begin; li != left.end() && ri != right.end(); oi++){
             if(*li <= *ri){
                 *oi = *li;
                li++;
             }
             else{
                 *oi = *ri;
                 ri++;
             }
         }
         if(li == left.end()){
             while(ri != right.end()){ *oi = *ri; oi++; ri++; }
         }
         else{
             while(li != left.end()){ *oi = *li; oi++; li++; }
         }
     }
template <typename iter>
void merge_sort(iter begin, iter end){
    if(begin == end){
        return;
    }
    iter mid = begin + (end-begin)/2;
    merge_sort(begin, mid);
    merge_sort(mid+1, end);
    merge(begin, mid, end);
}
int main(){
    std::vector<int> v1;
    for(int i = 0; i < 100; i++){
        v1.push_back(dist(gen));
    }
    merge_sort(v1.begin(), v1.end());
    assert(std::is_sorted(v1.begin(), v1.end()));
    std::cout<<"\n";
}
