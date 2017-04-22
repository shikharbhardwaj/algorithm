#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define TEST     \
int T;         \
std::cin >> T; \
while (T--)
using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using namespace std;

vector<string> grid;
vi min_x, min_y, max_x, max_y;
string steps;
int N, L;

bool check(int x, int y, int s) {
	int mnx = x + min_x[s];
	int mxx = x + max_x[s];
	int mny = y + min_y[s];
	int mxy = y + max_y[s];
	if (min(mnx, min(mny, min(mxx, mxy))) < 0 ||
		max(mnx, max(mny, max(mxx, mxy))) >= N) {
		return false;
}
return true;
}
int main() {
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
  	auto cinbuf = cin.rdbuf(fin.rdbuf());     // save and redirect
  	auto coutbuf = cout.rdbuf(fout.rdbuf());  // save and redirect
#endif
  	TEST {
  		cin >> L >> N;
  		grid.assign(N, "");
  		cin >> steps;
  		int blocks = 0;
  		for (int i = 0; i < N; ++i) {
  			cin >> grid[i];
  			if (find(grid[i].begin(), grid[i].end(), '#') != grid[i].end()) {
  				++blocks;
  			}
  		}
  		if (blocks == 0) {
      // Solving the second subtask
  			min_y.assign(L + 1, 0);
  			min_x.assign(L + 1, 0);
  			max_y.assign(L + 1, 0);
  			max_x.assign(L + 1, 0);
  			int cur_x = 0, cur_y = 0;
  			for (size_t i = 0; i < steps.size(); ++i) {
  				switch (steps[i]) {
  					case 'U':
  					++cur_y;
  					break;
  					case 'D':
  					--cur_y;
  					break;
  					case 'R':
  					++cur_x;
  					break;
  					default:
  					--cur_x;
  				}
  				min_x[i + 1] = min(min_x[i], cur_x);
  				min_y[i + 1] = min(min_y[i], cur_y);
  				max_x[i + 1] = max(max_x[i], cur_x);
  				max_y[i + 1] = max(max_y[i], cur_y);
  			}
  			int solution = 0;
  			for (int x = 0; x < N; ++x) {
  				for (int y = 0; y < N; ++y) {
  					int left = 0, right = L, mid, ans = 0;
  					while (left <= right) {
  						mid = (left + right) / 2;
  						if (check(x, y, mid)) {
  							ans = mid;
  							left = mid + 1;
  						} else {
  							right = mid - 1;
  						}
  					}
          // cout << ans << " ";
  					solution ^= ans;
  				}
        // cout << endl;
  			}
  			cout << solution << endl;
  		} else {
      // Brute FTW
	  // TODO: Optimize this 
  			int sol = 0;
  			for (int i = 0; i < N; ++i) {
  				for (int j = 0; j < N; ++j) {
  					if (grid[i][j] == '#') {
            // cout <<  "0 ";
  						continue;
  					}
  					int cur_x = j, cur_y = i;
  					int k;
  					for (k = 0; k < L; ++k) {
  						switch (steps[k]) {
  							case 'U':
  							--cur_y;
  							break;
  							case 'D':
  							++cur_y;
  							break;
  							case 'R':
  							++cur_x;
  							break;
  							default:
  							--cur_x;
  						}
  						if (cur_x < 0 || cur_x >= N || cur_y < 0 || cur_y >= N ||
  							grid[cur_y][cur_x] == '#') {
  							break;
  					}
  				}
          // cout << k << " ";
  				sol ^= k;
  			}
        // cout << endl;
  		}
  		cout << sol << endl;
  	}
  }
#ifndef ONLINE_JUDGE
  cin.rdbuf(cinbuf);    // restore
  cout.rdbuf(coutbuf);  // restore
#endif
}