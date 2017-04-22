#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

int o1, o2;
bool valid(const std::vector<int> &bits) {
	int N = o1 * o2;	
	for(int shift = 0; shift < o2; ++shift){
		int one_dist = 0;
		for(int i = shift; i < N + shift; i += o2){
			int one_cnt = 0;
			for(int j = i; j - i < o2; ++j){
				if(bits[j % N] == 1) ++one_cnt;
			}
			if(one_cnt >= o2 / 2 + 1) ++one_dist;
		}
		if(one_dist >= o1 / 2 + 1) {
			return true;
		}
	}
	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::ofstream out("out1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	int t;
	std::cin >> t;
	while(t--){
		std::cin >> o1 >> o2;
		int N = o1 * o2;
		std::vector<int> bits(o1 * o2);
		for(int i = 0; i < o1 * o2; i++){
			std::cin >> bits[i];
		}
		std::cout << (int)valid(bits) << std::endl;
		// std::cout << bits << std::endl;
		// std::vector<int> dists(N, 0);
		// int start = 0;
		// while(bits[start] == 0) ++start;
		// for(int i = start + 1; i < start + N; ++i){
		// 	int cur = i % N;
		// 	int prev = cur - 1;
		// 	if(prev < 0){
		// 		prev += N;
		// 	}

		// 	if(bits[cur] == 1){
		// 		dists[cur] = 0;
		// 	} else {
		// 		dists[cur] = dists[prev] + 1;
		// 	}
		// }
		// std::cout << dists << std::endl;
	}
}
