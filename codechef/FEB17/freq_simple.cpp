#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	int N, M;
	std::cin >> N >> M;
	std::vector<int> ar(N);
	std::vector<int> pre(N);
	std::vector<int> post(N);
	std::cin >> ar[0];
	pre[0] = 1;
	for (int i = 1; i < N; ++i) {
		std::cin >> ar[i];
		if(ar[i] == ar[i - 1]){
			pre[i] = pre[i - 1] + 1;
		} else{
			pre[i] = 1;
		}
	}
	post[N - 1] = 1;
	for(int i = N - 2; i >= 0; --i){ 
		if(ar[i] == ar[i + 1]){
			post[i] = post[i + 1] + 1;
		} else{
			post[i] = 1;
		}
	}
	int L, R, k;
	for(int i = 0; i < M; ++i){
		std::cin >> L >> R >> k;
		int mid = (R - L + 1) / 2;
		int num = pre[mid] + post[mid] - 1;
		if(num >= k){
			std::cout << ar[mid] << std::endl;
		} else {
			std::cout << "-1" << std::endl;
		}
	}
}
