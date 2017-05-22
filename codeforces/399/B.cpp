#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

using ull = unsigned long long;
ull log2(ull x){
	int ret = 0;
	while(x){
		x /= 2;
		++ret;
	}
	return ret;
}
ull compute_ans(ull x, int l, int r){
	if(x == 0) {
		return 0;
	}
	int mid = 1 << (log2(x) + 1);
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	std::cin.rdbuf(in.rdbuf());    // save and redirect
	std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
}
