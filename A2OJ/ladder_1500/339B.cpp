#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif
using ll = long long;

int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");
	auto cinbuf = std::cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	int n, m, ai;
	std::cin >> m >> n;
	ll cur_pos = 1, time = 0;
	for(int i = 0; i < n; ++i){
		std::cin >> ai;
		int dist = ai - cur_pos;
		if(dist < 0){
			dist += m;
		}
		time += dist;
		cur_pos = ai;
	}
	std::cout << time << std::endl;

#ifndef ONLINE_JUDGE
	std::cin.rdbuf(cinbuf);    // restore
	std::cout.rdbuf(coutbuf); // restore
#endif	
}
