#include <algorithm>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>
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
	int T;
	std::cin >> T;
	for (int i = 1; i <= T; ++i) {
		double N, M;
		std::cin >> N >> M;
		std::cout << "Case #" << i << ": " << std::fixed << std::setprecision(8) << (N - M) / (N + M) << std::endl;
	}
}
