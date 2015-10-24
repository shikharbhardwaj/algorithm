#include <cstdio>
#include <cmath>
int main(){
	int T, n;
	long long floatVal;
	long long intVal;
	bool found = false;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		found = false;
		for(int i = 1; i < n ; i++){
			intVal = (n-i)*(n+i);
			floatVal = sqrt(intVal);
			if(floatVal * floatVal == intVal){
				found = true;
				break;
			}
		}
		if(found){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}  
