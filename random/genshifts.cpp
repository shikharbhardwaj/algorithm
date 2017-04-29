#include <iostream>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> digits(0, 9);
const int len = 100;
int main(){
	std::cout << len << std::endl;
	for(int i = 0; i < len; i++){
		for(int j = 0; j < 6; j++){
			std::cout << digits(gen);
		}
		std::cout << std::endl;
	}
}