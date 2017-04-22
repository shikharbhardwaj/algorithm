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
	std::cin.rdbuf(in.rdbuf());    // save and redirect
	std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	int n;
	std::cin >> n;
	std::vector<int> ai(n);
	for(int i = 0; i < n; i++){
		std::cin >> ai[i];
	}
	std::sort(ai.begin(), ai.end());
	int cnt = 0;
	int last = ai[0];
	int most = ai[n - 1];
	for(int i = 1; i < n - 1; i++){
		if(last != ai[i] && most != ai[i]){
			cnt++;
		}
	}
	std::cout << cnt << std::endl;
}
