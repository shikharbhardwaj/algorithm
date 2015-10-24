#include <cstdio>
#include <cmath>
//Solution for OCT15/ADTRI
int gcd(int a, int b){
    int y = 0;
    int x = 0;
    int temp;
    if( a > b ){
        x = a;
        y = b;
    }
    else{
        x = b;
        y = a;
    }
    while( x % y ){
        temp = x;
        x = y;
        y = temp % x;
    }
    return y;
}
bool isHypotenuse(int in){
    bool found = false;
    int smax = ((float)in*(1.0+sqrt(2))); 
    //Calculating smin
    int smin = 0;
    int curval = sqrt(in*in - 1);
    if(curval == sqrt(in*in-1)){
        smin = in + 1 + curval;
    }
    else{
        smin = in + curval + 2;
    }
    for(int s = smin; s <= smax; s++){
        int m = 0, k = 0;
        int mlimit = (int) sqrt(s / 2);
        for (m = 2; m <= mlimit; m++) {
            if ((s / 2) % m == 0) { // m found
                if (m % 2 == 0) { // ensure that we find an odd number for k
                    k = m + 1;
                } else {
                    k = m + 2;
                }
                while (k < 2 * m && k <= s / (2 * m)) {
                    if (s / (2 * m) % k == 0 && gcd(k, m) == 1) {
                        found = true;
                        break;
                    }
                    k += 2;
                }
            }
            if (found) {
                return found;
            }
        } 
    }
    return found;
}
int main(){
    int T;
    long long n;
    scanf("%d", &T);
    while(T--){
        scanf("%lld", &n);
        if(isHypotenuse(n)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
