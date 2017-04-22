#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int cnt[27];
int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	std::string prg;
	char max_ch = 'a';
	bool correct = true;
	std::cin >> prg;
	if(prg[0] != 'a'){
		correct = false;
	}
	else{
		cnt[0] = 1;
		cnt[1] = 1;
		for(auto ch : prg){
			if(cnt[ch - 'a'] == 0){
				correct = false;
				break;
			} else{
				cnt[ch - 'a' + 1] = 1;
			}
		}
	}
	if(!correct){
		std::cout << "NO\n";
	} else{
		std::cout << "YES\n";
	}
}
