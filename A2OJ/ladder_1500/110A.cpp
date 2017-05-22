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
	long long n;
	std::cin >> n;
	int num_lucky = 0;
	while(n){
		int cur = n % 10;
		if(cur == 4 || cur == 7){
			++num_lucky;
		}
		n /= 10;
	}
	if(num_lucky == 4 || num_lucky == 7){
		std::cout << "YES\n";
	} else{
		std::cout << "NO\n";
	}

#ifndef ONLINE_JUDGE
	std::cin.rdbuf(cinbuf);    // restore
	std::cout.rdbuf(coutbuf); // restore
#endif	
}
