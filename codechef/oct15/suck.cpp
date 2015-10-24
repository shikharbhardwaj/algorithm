#include <cstdio>
#include <cmath>
unsigned int numbers[3500], len;
inline bool prime(unsigned int x)
{
    unsigned int i, last = sqrt(x);
    for (i = 2; i <= last; i++)
    {
        if (!(x % i))
        {
            return 0;
        }
    }
    return 1;
}
void generate()
{
    for (unsigned int i = 2; i < 32000; i++)
    {
        if (prime(i))
        {
            numbers[len++] = i;
        }
    }
}
inline bool process(unsigned long x)
{
    if(x == 1){
        return 0;
    }
    unsigned int i, last = sqrt(x);
    for (i = 0; i < len && numbers[i] <= last; i++)
    {
        if (!(x % numbers[i])) 
            return 0; 
    }
    return 1;
}
bool isHypotenuse(long long n){
    if(n%2 == 0){
        while(n%2 == 0){
            n /= 2;
        }
    }
    if(process(n)){
        if((n-1)%4 == 0){
            return true;
        }
        return false;
    }
    for (int i = 3; i <= sqrt(n); i = i+2){
        // While i divides n, print i and divide n
        if(n%i == 0){
            if((i-1)%4 == 0){
                return true;
            }
            n /= i;
        }
        while(n%i == 0){
            n/=i;
        }
    }
    if( n > 2 ){
        if((n-1)%4 == 0){
            return true;
        }
    }
    return false;
}
int main(){
    int T;
    int n;
    generate();
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        if(isHypotenuse(n)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
