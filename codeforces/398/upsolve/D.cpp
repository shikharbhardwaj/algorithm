#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

int sort_cnt[10000000];
int cartons[2000001];

bool check(int x) {

}
int lower_bound() {}

int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	std::cin.rdbuf(in.rdbuf());    // save and redirect
	std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	int n, m, k;
	std::cin >> n >> m >> k;

	for(int i = 0; i < n + m; ++i){
		std::cin >> cartons[i];
	}
}
