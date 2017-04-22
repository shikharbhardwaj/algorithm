#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	int N, snack;
	std::cin >> N;
	int req = N;
	std::priority_queue<int> rec;
	
	for (int i = 0; i < N; ++i) {
		std::cin >> snack;
		rec.push(snack);
		while(!rec.empty() && rec.top() == req){
			std::cout << rec.top() << " ";
			rec.pop();
			--req;
		}
		if(i != N-1){
			std::cout << std::endl;
		}
	}
}
