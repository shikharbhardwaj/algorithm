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
	int n, outgoing, incoming;
	std::cin >> n;
	int cur_people = 0, max_people = 0;
	for(int i = 0; i < n; ++i){
		std::cin >> outgoing >> incoming;
		cur_people -= outgoing;
		cur_people += incoming;
		if(max_people < cur_people){
			max_people = cur_people;
		}
	}
	std::cout << max_people << std::endl;

#ifndef ONLINE_JUDGE
	std::cin.rdbuf(cinbuf);    // restore
	std::cout.rdbuf(coutbuf); // restore
#endif	
}
