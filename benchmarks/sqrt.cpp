#include <stdio.h>
#include <math.h>
int main(){
	int T, in;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &in);
		printf("%d\n", (int)sqrt(in));
	}
	return 0;
}
