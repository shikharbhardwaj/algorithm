#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

int score(const std::string &in){
	std::vector<bool> alpha(26, false);
	for(auto ch : in){
		if(ch >= 'A' && ch <= 'Z')
			alpha[ch - 'A'] = true;
	}
	int ret = 0;
	for(auto val : alpha){
		if(val)
			++ret;
	}
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("A-large-practice.txt");
	std::ofstream out("out.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	int T;
	std::cin >> T;
	std::cin.ignore();

	for (int i = 1; i <= T; ++i) {
		int N;
		std::cin >> N;
		std::cin.ignore();

		std::string name;

		std::getline(std::cin, name);
		int max_score = score(name);
		std::string winner = name;

		for(int i = 1; i < N; ++i) {
			std::getline(std::cin, name);

			int cur_score = score(name);
			if(cur_score > max_score){
				winner = name;
				max_score = cur_score;
			}
			if(cur_score == max_score){
				if(name < winner){
					winner = name;
				}
			}
		}

		std::cout << "Case #" << i << ": " << winner << std::endl;
	}
}