#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)
using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using pii = std::pair<int, int>;
using namespace std;


vector<int> maxset(const vector<int> &A) {
	long long max_start, max_end, max_length = A.size();
	long long max_sum = -1, cur_sum = 0, cur_start = 0;
	for(size_t i = 0; i < A.size(); ++i){
		if(A[i] < 0){
			if(cur_sum > max_sum){
				max_sum = cur_sum;
				max_start = cur_start;
				max_end = i - 1;
				max_length = i - cur_start;
			}
			if(cur_sum == max_sum && max_length < i - cur_start){
				max_start = cur_start;
				max_end = i - 1;
				max_length = i - cur_start;
			}
			cur_sum = 0;
			cur_start = i + 1;
			continue;
		}
		cur_sum += A[i];
	}
    // Add the last remaining array
	if(cur_sum > max_sum){
		max_start = cur_start;
		max_end = A.size() - 1;
	}
	if(cur_sum == max_sum && max_length < A.size() - cur_start){
		max_start = cur_start;
		max_end = A.size() - 1;
	}
	return vector<int>(A.begin() + max_start, A.begin() + max_end + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
  auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
  auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
  cout << maxset({1967513926, 1540383426, -1303455736, -521595368}) << endl;
#ifndef ONLINE_JUDGE
  cin.rdbuf(cinbuf);    // restore
  cout.rdbuf(coutbuf); // restore
#endif	
}
