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
	std::string guest, host, pile;
	std::cin >> guest >> host >> pile;
	std::vector<int> hist(26, 0);
	std::vector<int> test(26, 0);
	for(auto elem : guest){
		++hist[elem - 'A'];
	}
	for(auto elem : host){
		++hist[elem - 'A'];
	}
	for(auto elem : pile){
		++test[elem - 'A'];
	}
	bool valid = true;
	for(int i = 0; i < 26; ++i){
		if(hist[i] != test[i]){
			valid = false;
		}
	}
	if(!valid){
		std::cout << "NO\n";
	} else{
		std::cout << "YES\n";
	}

#ifndef ONLINE_JUDGE
	std::cin.rdbuf(cinbuf);    // restore
	std::cout.rdbuf(coutbuf); // restore
#endif	
}
