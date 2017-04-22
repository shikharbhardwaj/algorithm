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
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	int N, pos;
	std::cin >> N >> pos;
	int offset = N % 6, ans;
	if(pos == 1){
		if(offset == 0 || offset == 3){
			ans = 1;
		} else{
			if(offset <= 2){
				ans = (N % 2) ? 0 : 2;
			} else{
				ans = (N % 2) ? 2 : 0;
			}
		}
	} else{
		offset += (N % 2 == 0 && pos == 2) ? 1 : 0;
		offset += (N % 2 && pos == 0) ? 1 : 0;
		if(offset < 0){
			offset += 6;
		}
		offset %= 6;
		if(offset <= 1){
			ans = pos;
		}
		else if(offset == 3 || offset == 4){
			ans = (pos == 0) ? 2 : 0;
		} else{
			ans = 1;
		}
	}
	std::cout << ans << std::endl;
#ifndef ONLINE_JUDGE
	std::cin.rdbuf(cinbuf);
	std::cin.rdbuf(coutbuf);
#endif
}