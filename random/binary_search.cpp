#include <iostream>
#include <vector>
template <typename T>	//Works with any type of data
size_t binary_search(std::vector<T> vec, T key){
	int mid, left, right;
	left = 0;
	right = vec.size()-1;
	while(left<right){
		mid = (left+right+1)/2;
		if(vec[mid] == key){
			return mid;
		}
		else if(vec[mid] < key){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
	return -1;
}
int main(){
	
	return 0;
}