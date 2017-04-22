#include <iostream>
#include <cmath>
#include <cstdio>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

const int N = 100000, M = 10000;

std::uniform_int_distribution<int> ai(0, 1e9);
std::uniform_int_distribution<int> L(1, N);
int main(){
	freopen("large.in", "w", stdout);
	std::cout << N << " " << M << std::endl;
	for(int i = 0; i < N; i++){
		std::cout << ai(gen) << " ";
	}
	std::cout << std::endl;
	for(int i = 0; i < M; i++){
		int lb = L(gen);
		std::uniform_int_distribution<int> R(lb, N);
		int rb = R(gen);
		std::uniform_int_distribution<int> k(ceil((rb - lb) / 2), rb - lb + 1);
		int kb = k(gen);
		std::cout << lb << " " << rb <<  " " << kb << std::endl;
	}
}