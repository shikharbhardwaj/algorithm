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
	std::string a, b;
	std::cin >> a >> b;
	for(size_t i = 0; i < b.size(); ++i){
		if(a[i] != b[i]){
			std::cout << "1";
		} else{
			std::cout << "0";
		}
	}
	std::cout << std::endl;

#ifndef ONLINE_JUDGE
	std::cin.rdbuf(cinbuf);    // restore
	std::cout.rdbuf(coutbuf); // restore
#endif	
}
