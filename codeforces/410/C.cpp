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

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	} else{
		return gcd(b, a % b);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	int N;
	cin >> N;
	vector<int> nums(N);
	FOR(i, N){
		cin >> nums[i];
	}
	int cur_gcd = nums[0];
	FOR(i, N - 1){
		cur_gcd = gcd(cur_gcd, nums[i + 1]);
	}
	if(cur_gcd > 1){
		cout << "YES\n";
		cout << "0\n";
	} else{
		// Ignore the even numbers, take consecutive odd pairs
		int steps = 0, cnt_odd = 0;
		for(int i = 0; i < N; ++i) {
			if(nums[i] % 2 == 0){
				if(cnt_odd == 1){
					steps += 2;
					cnt_odd = 0;
				}
				continue;
			} else{
				cnt_odd++;
				if(cnt_odd == 2){
					steps += 1;
					cnt_odd = 0;
				}
			}
		}
		if(cnt_odd == 1){
			steps += 2;
		}
		cout << "YES\n";
		cout << steps << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
