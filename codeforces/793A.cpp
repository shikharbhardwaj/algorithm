#include <algorithm>
#include <numeric>
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

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	int n, k;
	cin >> n >> k;
	vector<long long> a(n);
	FOR(i, n){
		cin >> a[i];
	}
	long long min_a = *min_element(a.begin(), a.end());
	transform(a.begin(), a.end(), a.begin(), [&](long long a){
		return a - min_a;
	});
	bool valid = true;
	FOR(i, n){
		if(a[i] % k != 0){
			valid = false;
			break;
		}
	}
	if(valid){
		transform(a.begin(), a.end(), a.begin(), [&](long long a){
			return a / k;
		});
		cout << accumulate(a.begin(), a.end(), (long long)0) << endl;
	} else{
		cout << "-1" << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
