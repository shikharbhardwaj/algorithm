#include <iostream>
#include <limits>
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(),
                                        std::numeric_limits<int>::max());
int main() { std::cout << dist(gen); }
