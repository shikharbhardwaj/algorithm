#include <iostream>
#include <algorithm>
namespace quick{
	inline void swap(int *a, int *b){
		int t = *a;
		*a = *b;
		*b = t;
	}
	void insertion_sort(int ar[], int lo, int hi){
		for(int i = lo+1;i<=hi;i++){
			int cur = ar[i];
			int j = i-1;
			while(ar[j] > cur && j >= lo){
				ar[j+1] = ar[j];
				j--;
			}
			ar[j+1] = cur;
		}
	}
	int partition(int ar[], int lo, int hi){
        //Hoare partition method
        //
        //Uses the crossing pointer method
        //to partition the array with the 
        //first element as the pivot
		int i = lo;
		int j = hi+1;
		while(true){
			while(ar[++i] < ar[lo]){
				if(i > hi) 
					break;
			}
			while(ar[lo] < ar[--j]);
			if(i >= j)
				break;
			swap(&ar[i], &ar[j]);
		}
		swap(&ar[lo], &ar[j]);
		return j;
	}
	void sub(int ar[], int lo, int hi){
		int diff = hi - lo;
		if(diff){
			if(diff < 8){
				insertion_sort(ar, lo, hi);
				return;
			}
			int j = partition(ar, lo, hi);
			sub(ar, lo, j-1);
			sub(ar, j+1, hi);
		}
	}
	void sort(int ar[], int size){
		sub(ar, 0, size-1);
	}
}
int ar[1000000];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n ; i++){
        scanf("%d", &ar[i]);
    }
    quick::sort(ar, n);
    for(int i = 0; i < n; i++){
        printf("%d\n", ar[i]);
    }
}
