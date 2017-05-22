#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");
	auto cinbuf = std::cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	std::string first, second;
	std::cin >> first >> second;
	std::transform(first.begin(), first.end(), first.begin(), ::tolower);
	std::transform(second.begin(), second.end(), second.begin(), ::tolower);
	if(first < second){
		std::cout << "-1" << std::endl;
	} else if(first == second){
		std::cout << "0" << std::endl;
	} else{
		std::cout << "1" << std::endl;
	}

#ifndef ONLINE_JUDGE
	std::cin.rdbuf(cinbuf);    // restore
	std::cout.rdbuf(coutbuf); // restore
#endif	
}
