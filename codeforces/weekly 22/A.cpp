#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

std::vector<int> digits(int n){
	std::vector<int> ret;
	while(n){
		ret.push_back(n % 10);
		n /= 10;
	}
	std::reverse(ret.begin(), ret.end());
	return ret;
}
int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	std::string str; 
	std::cin >> str;
	int cur = 1;
	int cur_num = 0;
	for(int i = 0; i < str.size(); i++){
		int cur_num = str[i] - '0';
		bool found = false;
		while(!found){
			auto nums = digits(cur);
			auto pos = std::find(nums.begin(), nums.end(), cur_num) - nums.begin();
			if(pos != nums.size()){
				found = true;
				++pos;
				++i;
				for(; pos < nums.size() && i < str.size(); ++pos){
					if(nums[pos] == str[i] - '0'){
						++i;
					} else{
						--i;
						break;
					}
				}
			}
			++cur;
		}
	}
	std::cout << cur - 1 << std::endl;
}
