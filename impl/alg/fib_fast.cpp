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
using sq_mat2 = std::array<std::array<ll, 2>, 2>;

using namespace std;

// Calculate Fibonacci numbers faster
sq_mat2 mult(const sq_mat2& a, const sq_mat2& b){
	sq_mat2 c;
	FOR(i, a.size()){
		FOR(j, b[0].size()){
			c[i][j] = 0;
			FOR(k, a[0].size()){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

sq_mat2 mat_exp(const sq_mat2 &b, size_t exp){
	if(exp == 0){
		return {{{1, 0}, {0, 1}}};
	}
	auto c = mat_exp(b, exp / 2);
	if(exp % 2 == 0){
		return mult(c, c);
	} else{
		return mult(mult(c, c), b);
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
	cout << mat_exp({{{1, 1}, {1, 0}}}, 22);
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
