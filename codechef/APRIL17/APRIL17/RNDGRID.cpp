#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>
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

vector<string> grid;
string steps;

vector<vector<int>> up;
vector<vector<int>> down;
vector<vector<int>> lt;
vector<vector<int>> rt;
unordered_map<int, int> threshold_top;
unordered_map<int, int> threshold_bottom;
unordered_map<int, int> threshold_left;
unordered_map<int, int> threshold_right;

int L, N;

int num_moves_possible(int i, int j){
	int up_max, down_max, lt_max, rt_max;
	if(threshold_top.find(up[i][j] + 1) == threshold_top.end()){
		up_max = steps.size();
	} else{
		up_max = threshold_top[up[i][j] + 1];
	}
	if(threshold_bottom.find(down[i][j] + 1) == threshold_bottom.end()){
		down_max = steps.size();
	} else{
		down_max = threshold_bottom[down[i][j] + 1];
	}
	if(threshold_left.find(lt[i][j] + 1) == threshold_left.end()){
		lt_max = steps.size();
	} else{
		lt_max = threshold_left[lt[i][j] + 1];
	}
	if(threshold_right.find(rt[i][j] + 1) == threshold_right.end()){
		rt_max = steps.size();
	} else{
		rt_max = threshold_right[rt[i][j] + 1];
	}
	return min(min(min(up_max, down_max), rt_max), lt_max);
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout	.rdbuf(fout.rdbuf()); // save and redirect
#endif	
	TEST{
		threshold_right.clear();
		threshold_left.clear();
		threshold_top.clear();
		threshold_bottom.clear();
		cin >> L >> N;
		grid.assign(N, "");

		cin >> steps;

		for(int i = 0; i < N; ++i){
			cin >> grid[i];
		}
		// Handle bad tests
		int num_blocked = 0;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				if(grid[i][j] == '#')
					++num_blocked;
			}
		}
		if(num_blocked == N * N){
			T++;
			continue;
		}

		up.assign(N, vector<int>(N, 0));
		down.assign(N, vector<int>(N, 0));
		lt.assign(N, vector<int>(N, 0));
		rt.assign(N, vector<int>(N, 0));
		for(int i = 0; i < N; ++i){
			if(grid[0][i] == '#'){
				up[0][i] = -1;
			} 
			if(grid[N - 1][i] == '#'){
				down[N - 1][i] = -1;
			}
			if(grid[i][0] == '#'){
				lt[i][0] = -1;
			}
			if(grid[N - 1][0] == '#'){
				rt[N - 1][0] = -1;
			}
		}
		for(int i = 1; i < N; ++i){
			for(int j = 0; j < N; ++j){
				if(grid[i][j] != '#'){
					up[i][j] = up[i - 1][j] + 1;
				} else{
					up[i][j] = -1;
				}
				if(grid[j][i] != '#'){
					lt[j][i] = lt[j][i - 1] + 1;
				} else{
					lt[j][i] = -1;
				}
			}
		}
		for(int i = N - 2; i >= 0; --i){
			for(int j = 0; j < N; ++j){
				if(grid[i][j] != '#'){
					down[i][j] = down[i + 1][j] + 1;
				} else{
					down[i][j] = -1;
				}
				if(grid[j][i] != '#'){
					rt[j][i] = down[j][i + 1] + 1;
				} else{
					rt[j][i] = -1;
				}
			}
		}
		// Process the limits
		int cur_u, cur_l, cur_r, cur_d;
		cur_u = cur_l = cur_r = cur_d = 0;
		for(size_t i = 0; i < steps.size(); ++i){
			if(steps[i] == 'U'){
				++cur_u;
				--cur_d;
				if(threshold_top.find(cur_u) == threshold_top.end()){
					threshold_top[cur_u] = i;
				}
				if(threshold_bottom.find(cur_d) == threshold_bottom.end()){
					threshold_bottom[cur_d] = i;
				}
			} else if(steps[i] == 'D'){
				++cur_d;
				--cur_u;
				if(threshold_bottom.find(cur_d) == threshold_bottom.end()){
					threshold_bottom[cur_d] = i;
				}
				if(threshold_top.find(cur_u) == threshold_top.end()){
					threshold_top[cur_u] = i;
				}
			}else if(steps[i] == 'L'){
				++cur_l;
				--cur_r;
				if(threshold_left.find(cur_l) == threshold_left.end()){
					threshold_left[cur_l] = i;
				}
				if(threshold_right.find(cur_r) == threshold_right.end()){
					threshold_right[cur_r] = i;
				}
			}else if(steps[i] == 'R'){
				++cur_r;
				--cur_l;
				if(threshold_right.find(cur_r) == threshold_right.end()){
					threshold_right[cur_r] = i;
				}
				if(threshold_left.find(cur_l) == threshold_left.end()){
					threshold_left[cur_l] = i;
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				if(grid[i][j] != '#'){
					int res = num_moves_possible(i, j);
					cout << res << " : ";
					ans ^= res;
				} else{
					cout << "0 : ";
				}
			}
			cout << endl;
		}
		cout << ans << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
