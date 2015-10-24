#include <cstdio>
#include <limits>
#include <random>
#include <chrono>
#include <algorithm>
#include "quick_sort.cpp"
#define SIZE 1000000
void genRandom(int* ar, int size){
	std::random_device rng;
	std::mt19937 mt(rng());
	std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
	for(int i = 0;i<size;i++){
		ar[i] = dist(rng);
	}
}
int main(){
	int *ar = new int[SIZE];
	long long time = 0;
	for(int i = 0;i<100;i++){
		printf("Begin test...\n");
		printf("Testing quickSort : ");
		printf("Generating random input...");
		fflush(stdout);
		genRandom(ar, SIZE);
		printf("Done\nSorting array : ");
		fflush(stdout);
		auto start = std::chrono::high_resolution_clock::now();
		std::sort(ar, &ar[SIZE]);
		auto end = std::chrono::high_resolution_clock::now();
		printf("Done\n");
		fflush(stdout);
		printf("Testing sort...\n");
		printf("%d\n", std::is_sorted(ar, &ar[SIZE]));
		time += std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
	}
	printf("Time taken : ");
	printf("%lld\n", time/100);
	delete[] ar;
}