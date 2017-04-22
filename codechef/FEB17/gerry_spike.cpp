#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif


int o1, o2;

bool valid(const std::vector<int> &bits) {
	std::vector<int> state_sum(o1, 0);
	int N = o1 * o2;
	for(int i = 0; i < N; ++i){
		state_sum[i / o2] += bits[i];
	}
	for(int i = 0; i < o2; ++i){
		int winning = 0;
		for(auto elem : state_sum){
			if(elem > o2 / 2) ++winning;
		}
		if(winning > o1 / 2) return true;

		for(int j = 0; j < o1; ++j){
			int cur = j * o2 + i;
			int next = (cur + o2) % N;
			state_sum[j] -= bits[cur];
			state_sum[j] += bits[next];
		}
	}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::ofstream out("out2.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	int T;
	std::cin >> T;
	while(T--){
		int one_cnt = 0;
		std::cin >> o1 >> o2; 
		std::vector<int> bits(o1 * o2);
		for(auto &elem : bits){
			std::cin >> elem;
			if(elem) ++one_cnt;
		}
		std::cout << (int)valid(bits) << std::endl;
	}
}
