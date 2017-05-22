#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>


std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dist(0, 1);
int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::ofstream out("test_in.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	int T = 100;
	std::cout << T << std::endl;
	int o1 = 5, o2 = 3;
	for(int i = 0; i < T; i++){
		std::cout << o1 << " " << o2 << std::endl;
		for(int i = 0; i < o1 * o2; i++){
			std::cout << dist(gen) << " ";
		}
		std::cout << std::endl;
	}
}
