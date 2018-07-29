#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
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
typedef pair<int, int> ii;

int n, m, k, x[500], y[500];

int min_coord(vector<ii> &points, int width, int height, int t) {
	sort(points.begin(), points.end());
	set<int> candidates;

	// We may need to insert one in the start.
	candidates.insert(1);


	for (size_t i = 0; i < points.size(); ++i) {
		if (points[i].first + t + 1 > width) break;
		// if (points[i].first - points[i - 1].first > 2 * t)
		candidates.insert(points[i].first + t + 1);
	}
	cout << candidates << endl;

	// Check which candidate should be placed.
	for (int ret : candidates) {
		vector<ii> sweep;
		int overlap = 0;
		for (auto p : points) {
			// We did not pass the point.
			if (p.first < ret - t) continue;
			// We crossed over the point.
			if (p.first > ret + t) break;
			// We are within t distance of the point.
			// Check if we cover the beginning of the strip.
			if (p.second - t <= 1) {
				--overlap;
			} else {
				sweep.emplace_back(p.second - t, -1);
			}
			sweep.emplace_back(p.second + t + 1, 1);
		}
		if (overlap == 0) return ret;
		sort(sweep.begin(), sweep.end());
		cout << "For <" << ret << ">\n";
		cout << sweep << endl;
		for (auto s : sweep) {
			if (s.first > height) break;
			overlap += s.second;
			if (overlap == 0) return ret;
		}
	}
	// Everything was covered, we need not place anything.
	return width + 1;
}

bool check(int t) {
	vector<ii> byx, byy;
	for (int i=0; i<k; ++i) {
		byx.emplace_back(x[i], y[i]);
		byy.emplace_back(y[i], x[i]);
	}
	int nx = min_coord(byx, n, m, t);
	int ny = min_coord(byy, m, n, t);
	if (nx > n) return true;
	cout << "Filled at : " << make_pair(min(nx + t, n), min(ny + t, m)) << endl;
	byx.emplace_back(min(nx+t, n), min(ny+t, m));
	return min_coord(byx, n, m, t) > n;
}


int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	cin >> n >> m >> k;
	for(int i = 0; i < k; ++i) {
		cin >> x[i] >> y[i];
	}

	// int low = 0, high = max(n, m);
	// while (low < high) {
	// 	int mid = low + high >> 1;
	// 	if (check(mid))
	// 		high = mid;
	// 	else
	// 		low = mid + 1;
	// }

	cout << boolalpha <<  check(3) << endl;

	// cout << low << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
