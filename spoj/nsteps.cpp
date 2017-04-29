#include <cstdio>
int min(int x, int y){
	if(x > y)
		return y;
	return x;
}
int max(int x, int y){
	if(x > y)
		return x;
	return y;
}
int main(){
	register int N,x,y;
	scanf("%d", &N);
	while(N--){
		scanf("%d%d",&x,&y);
		if(x%2 && y%2){
			printf("%d\n", x+y-1);
		}
		else if(x%2 == 0 && y%2 == 0){
			printf("%d\n", x+y);
		}
		else{
			printf("No Number\n");
		}
	}
}