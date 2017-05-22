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

vector<int> A, B, wt;
vector<float> val;
// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, int n) {
	int state[n+1][W+1];

	for(int i = 0; i <= n; i++) {
		for(int w = 0; w <= W; w++) {
			if (i==0 || w==0)
				state[i][w] = 0;
			else if (wt[i-1] <= w)
				state[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
			else
				state[i][w] = K[i-1][w];
		}
	}
	return K[n][W];
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
	A.assign(N, 0);
	B.assign(N, 0);
	FOR(i, N){
		cin >> A[i];
	}
	FOR(i, N){
		cin >> B[i];
	}
	long long sumA = std::accumulate(A.begin(), A.end(), (long long)0);
	long long sumB = std::accumulate(B.begin(), B.end(), (long long)0);
	val.assign(N, 0);
	FOR(i, N){
		val[i] = (float)A[i] / sumA + (float)B[i] / sumB;
	}
	wt.assign(N, 1);
	cout << knapsack(N / 2 + 1, N) << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
