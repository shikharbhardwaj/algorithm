#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
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
	TEST{
		int n, m;
		cin >> n >> m;
		vector<vi> grid1(n);
		vector<vi> dist(n);
		int max_val = 0;
		FOR(i, n){
			grid1[i].resize(m);
			dist[i].resize(m);
			FOR(j, m){
				cin >> grid1[i][j];
				max_val = max(max_val, grid1[i][j]);
				dist[i][j] = 1e5;
			}
		}
		FOR(i, n) {
			FOR(j, m) {
				if(grid1[i][j] == max_val){
					dist[i][j] = 0;
				}
			}
		}
		cout << dist << endl;
		FOR(i, n){
			FOR(j, m){
				if(i > 0){
					dist[i][j] = min(dist[i - 1][j] + 1, dist[i][j]);
				}
				if(i != n - 1){
					dist[i][j] = min(dist[i + 1][j] + 1, dist[i][j]);
				}
				if(j > 0){
					dist[i][j] = min(dist[i][j - 1] + 1, dist[i][j]);
				}
				if(j != m - 1){
					dist[i][j] = min(dist[i][j + 1] + 1, dist[i][j]);
				}
				if(i > 0 && j > 0){
					dist[i][j] = min(dist[i - 1][j - 1] + 1, dist[i][j]);
				}
				if(i > 0 && j != m - 1){
					dist[i][j] = min(dist[i - 1][j + 1] + 1, dist[i][j]);
				}
				if(i != n - 1 && j > 0){
					dist[i][j] = min(dist[i + 1][j - 1] + 1, dist[i][j]);
				}
				if(i != n - 1 && j != m - 1){
					dist[i][j] = min(dist[i + 1][j + 1] + 1, dist[i][j]);
				}	
			}
		}
		max_val = 0;
		FOR(i, n){
			FOR(j, m){
				max_val = max(max_val, dist[i][j]);
			}
		}
		cout << max_val << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}