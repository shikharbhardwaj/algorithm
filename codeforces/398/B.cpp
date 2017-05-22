#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

using ll = long long;

int main(){
	std::ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());    // save and redirect
	auto coutbuf = std::cout.rdbuf(out.rdbuf()); // save and redirect
#endif	
	ll ts, tf, t;
	int N;

	std::cin >> ts >> tf >> t;
	std::cin >> N;
	ll arrival_time, wait_time = 1e17;
	if(N > 0){
		std::vector<ll> times(N);
		for (int i = 0; i < N; ++i) {
			std::cin >> times[i];
		}
		std::vector<ll> serve_times(N, -1);
		serve_times[0] = (times[0] <= ts) ? ts : times[0];
		for(int i = 1; i < N; i++){
			if(times[i] < serve_times[i - 1] + t){
				serve_times[i] = serve_times[i - 1] + t;
			} else{
				serve_times[i] = times[i];
			}
			if(serve_times[i] > tf -  t){
				serve_times[i] = -1;
				break;
			}
		}
		// Arrive after everyone
		if(serve_times[N - 1] != -1 && serve_times[N - 1] + t <= tf - t){
			arrival_time = serve_times[N - 1] + t;
			wait_time = 0;
		}
		// Or earlier than everyone
		if(wait_time != 0 && serve_times[0] != -1){
			if(times[0] > ts){
				arrival_time = ts;
				wait_time = 0;
			} else{
				arrival_time = times[0] - 1;
				wait_time = serve_times[0] - times[0] + 1;
			}
		}
		if(wait_time != 0){
			// Stand in front of each visitor and check for minimum time spent
			for(int i = 1; i < N; ++i){ 
				if(serve_times[i] < 0)
					break;

				if(times[i] > serve_times[i - 1] + t){
					arrival_time = serve_times[i - 1] + t;
					wait_time = 0;
					break;
				}
				if(wait_time > serve_times[i] - times[i] + 1){
					wait_time = serve_times[i] - times[i] + 1;
					arrival_time = times[i] - 1;
				}
			}
		}
	} else{
		arrival_time = ts;
		wait_time = 0;
	}
	std::cout << arrival_time << std::endl;
}