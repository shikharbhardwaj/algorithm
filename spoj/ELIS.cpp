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

// Find the longest increasing subsequence 

template <typename T>
void lis(const vector<T>& A, vector<size_t>& lens){
	lens.assign(A.size(), 1);
	for(size_t i = 1; i < A.size(); ++i){
		for(size_t j = 0; j < i; ++j){
			if(A[j] < A[i]){
				lens[i] = max(lens[i], lens[j] + 1);
			}
		}
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
	vector<int> A(N);
	FOR(i, N){
		cin >> A[i];
	}
	vector<size_t> l;
	lis(A, l);
	cout << *max_element(l.begin(), l.end()) << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
