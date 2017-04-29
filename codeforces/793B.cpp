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

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	int n, m;
	cin >> n >> m;
	vector<string> grid(n, "");
	vector<vector<int>> num_turns(n, vector<int>(m, -1));
	FOR(i, n){
		cin >> grid[i];
	}
	int dest_x, dest_y, src_x, src_y;
	FOR(i, n){
		FOR(j, m){
			if(grid[i][j] == 'T'){
				dest_x = j;
				dest_y = i;
			}
			if(grid[i][j] == 'S'){
				src_x = j;
				src_y = i;
			}
		}
	}
	for(int i = dest_x - 1; i >= 0; --i){
		if(grid[dest_y][i] == '.'){
			num_turns[dest_y][i] = 0;
		} else{
			break;
		}
	}
	for(int i = dest_x + 1; i < m; ++i){
		if(grid[dest_y][i] == '.'){
			num_turns[dest_y][i] = 0;
		} else{
			break;
		}
	}
	for(int i = dest_y - 1; i >= 0; --i){
		if(grid[i][dest_x] == '.'){
			num_turns[i][dest_x] = 0;
		} else{
			break;
		}
	}
	for(int i = dest_y + 1; i < n; ++i){
		if(grid[i][dest_x] == '.'){
			num_turns[i][dest_x] = 0;
		} else{
			break;
		}
	}
	for(int i = src_x - 1; i >= 0; --i){
		if(grid[src_y][i] == '.'){
			num_turns[src_y][i] = 1;
		} else{
			break;
		}
	}
	for(int i = src_x + 1; i < m; ++i){
		if(grid[src_y][i] == '.'){
			num_turns[src_y][i] = 1;
		} else{
			break;
		}
	}
	for(int i = src_y - 1; i >= 0; --i){
		if(grid[i][src_x] == '.'){
			num_turns[i][src_x] = 1;
		} else{
			break;
		}
	}
	for(int i = src_y + 1; i < n; ++i){
		if(grid[i][src_x] == '.'){
			num_turns[i][src_x] = 1;
		} else{
			break;
		}
	}
	bool found = false;
	num_turns[dest_y][dest_x] = 0;
	num_turns[src_y][src_x] = 1;
	FOR(i, n){
		if(found)
			break;
		int num_s = 0;
		int num_d = 0;
		FOR(j, m){
			if(num_turns[i][j] == 1){
				++num_s;
			}
			if(num_turns[i][j] == 0){
				++num_d;
			}
			if(num_s >= 1 && num_d >= 1){
				found = true;
				break;
			}
			if(grid[i][j] == '*'){
				num_s = 0;
				num_d = 0;
			}
		}
	}
	FOR(j, m){
		if(found)
			break;
		int num_s = 0;
		int num_d = 0;
		FOR(i, n){
			if(num_turns[i][j] == 1){
				++num_s;
			}
			if(num_turns[i][j] == 0){
				++num_d;
			}
			if(num_s >= 1 && num_d >= 1){
				found = true;
				break;
			}
			if(grid[i][j] == '*'){
				num_s = 0;
				num_d = 0;
			}
		}
	}
	// cout << num_turns << endl;
	cout << ((found) ?  "YES" : "NO") << endl;
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
