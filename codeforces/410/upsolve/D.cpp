#include <algorithm>
#include <iterator>
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
	vector<pii> A(N);
	vector<int> B(N);
	FOR(i, N){
		cin >> A[i].first;
		A[i].second = i;
	}
	FOR(i, N){
		cin >> B[i];
	}
	// cout << A << endl;
	sort(A.begin(), A.end(), [](const pii& l, const pii& r){
		return l.first > r.first;
	});
	// cout << A << endl;
	vector<int> p(N / 2 + 1);
	p[0] = A[0].second;
	for(int i = 1; 2 * i < N; ++i) {
		p[i] = (B[A[2 * i - 1].second] > B[A[2 * i].second]) ? A[2 * i - 1].second : A[2 * i].second;
	}
	if(N % 2 == 0) {
		p[N / 2] = A[N - 1].second;
	}
	transform(p.begin(), p.end(), p.begin(), [](int a){ return ++a; });
	cout << N / 2 + 1 << endl;
	copy(p.begin(), p.end(), ostream_iterator<int>(cout, " "));
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
