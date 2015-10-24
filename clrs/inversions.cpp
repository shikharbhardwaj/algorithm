#include <iostream>
#include <cassert>
#include <algorithm>
int inversions = 0;
void merge(int ar[], int left, int mid, int right){
    int *lar = new int [mid - left + 1];
    int *rar = new int [right - mid];
    for(int i = left; i <= mid ;i++){
        lar[i-left] = ar[i];
    }
    for(int i = mid+1; i <= right; i++){
        rar[i-mid-1] = ar[i];
    }
    int j, k, i;
    j = k = 0;
    for(i = left; i <= right && j <= mid - left && k < right - mid; i++){
        if(rar[j] < lar[k]){
            //The left array had the smaller element
            ar[i] = rar[k++];
        }
        else{
            ar[i] = lar[j++];
            inversions++;
        }
    }
    if(j <= mid - left){
        while(j < mid-left){
            ar[i++] = lar[j++];
        }
    }
    else if(k < right - mid){
        while(k < right - mid){
            ar[i++] = rar[k++];
        }
    }
    delete[] lar;
    delete[] rar;
}
void merge_sort(int ar[], int left, int right){
    if(left < right){
        int mid = (left+right)/2;
        merge_sort(ar, left, mid);
        merge_sort(ar, mid+1, right);
        merge(ar, left, mid, right);
    }
}
int main(){
    int ar[] = {2, 3, 8, 6, 1};
    merge_sort(ar, 0, 4);
    for(auto elem : ar){
        std::cout<<" : "<<elem;
    }
    assert(std::is_sorted(ar, ar+6));
    std::cout<<"\nNumber of inversions : "<<inversions;
}
