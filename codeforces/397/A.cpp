#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <vector>

int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	std::string line;
	std::string home;
	int n;
	std::cin >> n;
	std::cin >> home;
	std::unordered_map<std::string, int> detail;
	for (int i = 0; i < n; ++i) {
		std::cin >> line;
		std::string origin = line.substr(0, 3);
		std::string dest  = line.substr(5, 3);
		if(detail.find(origin) == detail.end()){
			detail[origin] = -1;
		} else{
			detail[origin] -= 1;
		}
		if(detail.find(dest) == detail.end()){
			detail[dest] = 1;
		} else{
			detail[dest] += 1;
		}
	}
	if(detail[home] != 0){
		std::cout << "contest" << std::endl;
	} else{
		std::cout << "home" << std::endl;
	}
}
