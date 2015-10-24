#include <iostream>
#include <algorithm>
#include <cassert>
#include <random>
#define size_type int
const int SIZE =  1000;
std::random_device rng;
std::mt19937 mt(rng());
template <typename T>
void insertion_sort(T ar[], size_type lo, size_type hi){
	for(size_type i = lo+1;i<=hi;i++){
		T cur = ar[i];
		size_type j = i-1;
		while(j >= lo && ar[j] > cur){
			ar[j+1] = ar[j];
			j--;
		}
		ar[j+1] = cur;
	}
}
template <typename T>
inline void swap(T *x, T *y){
	T temp = *x;
	*x = *y;
	*y = temp;
}
template <typename T>
size_type partition(T ar[], size_type lo, size_type hi){
	//Partition the array. first element is pivot
	size_type i = lo, j = hi+1;
	while(true){
		while(ar[++i] < ar[lo]){
			if(i == hi){
				break;
			}
		}
		while(ar[lo] < ar[--j]);
		if(i >= j)
			break;
		swap(&ar[i], &ar[j]);
	}
	swap(&ar[j], &ar[lo]);
	return j;
}
template <typename T>
void sort(T ar[], size_type lo, size_type hi){
	if(hi - lo < 0){
		return;
	}
	if(hi - lo <= 6){
		insertion_sort(ar, lo, hi);
		return;
	}
	size_type j = partition(ar, lo, hi);
	sort(ar, lo, j-1);
	sort(ar, j+1, hi);
}
int main(){
	std::uniform_int_distribution<unsigned int> dist;
	int ar[SIZE];
	for(int i = 0;i<SIZE;i++){
		ar[i] = dist(rng);
	}
	sort(ar, 0, SIZE-1);
	assert(std::is_sorted(ar, ar+SIZE));
	std::cout<<"Success"<<std::endl;
	return 0;
}
