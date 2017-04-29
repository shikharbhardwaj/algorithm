//Problem : AGGRCOW SPOJ
//Submission by bluefog
#include <iostream>
#include <algorithm>
int T, N, C;
int positions[100001];
bool placed(int x){
	int cows_placed = 1;
	int last_pos = positions[0];
	for(int cnt = 1;cnt<N;cnt++){
		if(positions[cnt] - last_pos >= x){
			cows_placed++;
			last_pos = positions[cnt];
			if(cows_placed == C){
				return true;
			}
		}
	}
	return false;
}
int getMaxDist(){
	int low = 0;
	int high = positions[N-1];
	while(low < high){
		int mid = (high+low)/2;
		if(placed(mid) == true){
			low = mid + 1;
		}
		else{
			high = mid;
		}
	}
	return low-1;
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &C);
		for(int i = 0;i<N;i++){
			scanf("%d",&positions[i]);
		}
		positions[N] = -1;
		std::sort(&positions[0], &positions[N]);	//Sort the positions
		printf("%d\n", getMaxDist());
	}
}