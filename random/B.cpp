#include <algorithm>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
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

bool definitelyLessThan(float a, float b, float epsilon = 1e-6)
{
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	double r, d, x, y, t;
	cin >> r >> d;
	int N, cnt = 0;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> x >> y >> t;

		double origin = sqrt(x * x + y * y);
		double mindist = origin - t;
		double maxdist = origin + t;
		if(mindist < 0)
			continue;
		// cout << r - d << ", " << mindist << endl;
		// cout << r + d << ", " << maxdist << endl;
		if(r - d <= mindist && maxdist <= r) {
			// cout << "Selected : " << i << endl;
			++cnt;
		}
	}
	cout << cnt << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
