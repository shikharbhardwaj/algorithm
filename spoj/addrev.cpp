#include <cstdio>
#include <cmath>
long long revNo(long long N){
	long long ret = 0;
	while(N>0){
		ret += N%10;
		ret *= 10;
		N /= 10;
	}
	ret /= 10;
	return ret;
}
int main(){
	long long N, a, b;
	scanf("%lld", &N);
	while(N--){
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", revNo(revNo(a) + revNo(b)));
	}
	return 0;
}