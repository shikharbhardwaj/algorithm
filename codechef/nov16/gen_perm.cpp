#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

long long fact(long long i){
	if(i == 1)
		return 1;
	return i * fact(i - 1);
}
int main(){
	int N;
	std::cin >> N;
	std::vector<int> ar(N);
	int n = 1;
	std::generate(ar.begin(), ar.end(), [&n] {return n++;});
	long long cnt = 0;
	for(long long i = 0; i < fact(N); i++){
		std::next_permutation(ar.begin(), ar.end());
		for(int i = 1; i < N - 1; i++){
			if(std::is_sorted(ar.begin(), ar.begin() + i + 1) && std::is_sorted(ar.begin() + i, ar.end(), std::greater<int>())){
				cnt++;
			}
		}
	}
	std::cout << cnt << "\n";
}