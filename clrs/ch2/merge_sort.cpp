#include <iostream>
#include <cassert>
#include <algorithm>
#include <random>
#include <vector>
#include <limits>
#include "../implementations/common.hpp"
template <typename iter, 
         typename T = typename std::iterator_traits<iter>::value_type, 
         typename comp = typename std::less<T>>
     void merge(iter begin, iter mid, iter end){
        //Merge the ranges pointed by [begin, mid-1] and [mid, end)
        //Number of elements in range[begin, mid] : mid - begin
        //Number of elements in range[mid+1, end) : end - mid
         if(*mid >= *(mid-1)){
             return;
         }
         std::vector<T> left(mid - begin);
         std::vector<T> right(end - mid);
         for(iter i = begin; i < mid; i++){
             left[i-begin] = std::move(*i);
         }
         for(iter i = mid; i < end; i++){
             right[i-mid] = std::move(*i);
         }
         iter li, ri, oi;
         li = left.begin();
         ri = right.begin();
         for(oi = begin; li != left.end() && ri != right.end(); oi++){
             if(*li <= *ri){
                 *oi = std::move(*li);
                li++;
             }
             else{
                 *oi = std::move(*ri);
                 ri++;
             }
         }
         if(li == left.end()){
             while(ri != right.end()){ *oi = std::move(*ri); oi++; ri++; }
         }
         else{
             while(li != left.end()){ *oi = std::move(*li); oi++; li++; }
         }
     }
template <typename iter>
void merge_sort(iter begin, iter end){
    if(end - begin < 2){
        return;
    }
    iter mid = begin + (end-begin)/2;
    merge_sort(begin, mid);
    merge_sort(mid, end);
    merge(begin, mid, end);
}
int main(){
    std::vector<int> v1(1000);
    algo::fill_random(v1.begin(), v1.end());
    merge_sort(v1.begin(), v1.end());
    assert(std::is_sorted(v1.begin(), v1.end()));
}
