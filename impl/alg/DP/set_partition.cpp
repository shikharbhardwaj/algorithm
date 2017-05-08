#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(size_t i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)

using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;

using namespace std;

int min_diff(const vi& nums) {
	// How would you solve this problem?
	// What decision, do we keep this element in the first set or the second one?
	int sum = accumulate(nums.begin(), nums.end(), 0);
	vector<vi> state(nums.size() + 1);
	for_each(state.begin(), state.end(), [&](vi& in){
		in.resize(sum + 1, 0);
	});
	FOR()
	for_each(state.begin(), state.end(), [&](vi& in){
		cout << in << endl;
	});
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	TEST{
		size_t N;
		cin >> N;
		vector<int> nums(N);
		FOR(i, N){
			cin >> nums[i];
		}
		cout << min_diff(nums) << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
