#include <bits/stdc++.h>
using namespace std;
int T, N;
bool sieve[5000005];
bool pyth[5000005];
vector<int> primes;
bool check(int n) {
    if (n<5){
		return false;
    }
    return pyth[n];
}
void pre() {
	for(int i = 2; i < 5000005; i++) {
        if (sieve[i]){
            continue;
        }
		primes.push_back(i);
        for(int j = i*2; j < 5000005;j += i){
			sieve[j] = 1;
        }
	}
	for(size_t i = 0;i < primes.size();i++) {
		if(((primes[i]-1)%4 == 0)) {
            for(int j = primes[i]; j < 5000005; j += primes[i]){ 
				pyth[j] = 1;
            }
		}
	}
}
int main() {
	pre();
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        printf("%d\n", check(N));
    }
	return 0;
}
