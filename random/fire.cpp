#include <algorithm>
#include <fstream>
#include <iostream>
#include <cmath>
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

const int KMAX = 502;

vector<int> xs(KMAX), ys(KMAX);
int n, m, k;

int minx(const vector<pair<int, int>> &points, int w, int h, int t) {
	// Check if the x direction is continuous.
	vector<int> candidates;
	candidates.reserve(k);

	candidates.push_back(1);

	for(int i = 0; i < k; ++i) {
		if(points[i].first + t + 1 > w) break;
		candidates.push_back(points[i].first + t + 1);
	}

	// cout << candidates << endl;

	for(int test : candidates) {
		vector<pair<int, int>> ranges;

		int overlap = 0;
		for(auto p : points) {
			if(p.first + t < test) continue;
			if(p.first - t > test) break;
			// We are within t distance of the candidate point.
			if(p.second <= t + 1) {
				// We started the beginning.
				--overlap;
			} else {
				// Begin a range.
				ranges.emplace_back(p.second - t, -1);
			}
			// End the (half open) range.
			ranges.emplace_back(p.second + t + 1, 1);
		}

		if(!overlap) {
			// We didnt start the range, this is the x co ord to be filled in.
			return test;
		}
		sort(ranges.begin(), ranges.end());
		// cout << "For <" << test << ">\n";
		// cout << ranges << endl;
		for(auto r : ranges) {
			if(r.first > h)
				break;
			overlap += r.second;
			if(overlap == 0) {
				// Discontinuity.
				return test;
			}
		}
	}
	return w + 1;
}

bool isIgnited(int t) {
	vector<pair<int, int>> checkxPoints(k);
	vector<pair<int, int>> checkyPoints(k);
	for(int i = 0; i < k; ++i) {
		checkyPoints[i].second = checkxPoints[i].first = xs[i];
		checkyPoints[i].first = checkxPoints[i].second = ys[i];
	}
	sort(checkxPoints.begin(), checkxPoints.end());
	sort(checkyPoints.begin(), checkyPoints.end());

	int x0 = minx(checkxPoints, n, m, t);
	int y0 = minx(checkyPoints, m, n, t);


	y0 = min(m, y0 + t);
	x0 = min(n, x0 + t);

	// cout << "Filled at " << make_pair(x0, y0);

	checkxPoints.emplace_back(x0, y0);

	sort(checkxPoints.begin(), checkxPoints.end());

	return (minx(checkxPoints, n, m, t) == n + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out2.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	cin >> n >> m >> k;

	for(int i = 0; i < k; ++i) {
		cin >> xs[i] >> ys[i];
	}

	int first = 0;
	int cnt = max(n, m);

	// Perform a lowerbound search.
	while(cnt > 0) {
		int step = cnt / 2;
		int test = first + step;

		if(!isIgnited(test)) {
			first = ++test;
			cnt -= step + 1;
		} else {
			cnt = step;
		}
	}

	cout << first << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
