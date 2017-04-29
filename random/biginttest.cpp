#include <iostream>
#include <random>
#include <limits>
#include <cassert>
const int TESTS = 1000;
std::random_device rng;
std::mt19937 mt(rng());
int main(int argc, char const *argv[]){
	std::uniform_int_distribution<int> dist(0, std::numeric_limits<int>::max());
	int T = TESTS;
	std::cout<<TESTS<<"\n";
	while(T--){
		int x = dist(rng);
		int y = dist(rng);
		std::cout<<x<<" "<<y;
	}
	assert(false);
	return 0;
}