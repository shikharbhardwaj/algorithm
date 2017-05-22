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

void indent(int n){
	while(n--){
		cout << " ";
	}
}
void pattern(int n){
	std::cout << "0";
	for(int i = 1; i <= n; ++i){
		std::cout << " " << i;
	}
	for(int i = n - 1; i >= 0; --i){
		std::cout << " " << i;
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
	int n;
	std::cin >> n;
	for(int i = 0; i <= n; ++i){
		indent(2 * (n - i));
		pattern(i);
		std::cout << "\n";
	}
	for(int i = n - 1; i >= 0; --i){
		indent(2 * (n - i));
		pattern(i);
		if(i != 0){
			std::cout << "\n";
		}
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
