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
	int n, k, x;
	std::cin >> n >> k >> x;
	std::vector<int> a(n);
	for(int i = 0; i < n; ++i){
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	for(int j = 0; j < k; ++j) {
		for(int i = 0; i < n; i += 2){
			a[i] ^= x;
		}
		std::sort(a.begin(), a.end());
	} 
	std::cout << a[n - 1] << " " << a[0] << std::endl;
}