/* 
 * C++ Program to Implement Miller Rabin Primality Test
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
#define ll long long
#define gc getchar_unlocked
void getfast_int(int &x){
    int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
using namespace std;
std::vector<int> pythoPrimes; 
int memo[5000001];
/* 
 * calculates (a * b) % c taking into account that a * b might overflow 
 */
ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {    
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
/* 
 * modular exponentiation
 */
ll modulo(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
 
/*
 * Miller-Rabin primality test, iteration signifies the accuracy
 */
bool Miller(ll p,int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2==0)
    {
        return false;
    }
    ll s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}
bool isHypotenuse(int n){
    if(n%2 == 0){
        while(n%2 == 0){
            n /= 2;
        }
    }
    if((n-1)%4 == 0){
        if(Miller(n, 4)){
            return true;
        }
    }
    for(auto elem : pythoPrimes){
        if( n%elem == 0 ){
            return true;
        }
        if(elem > n){
            return false;
        }
    }
    for (int i = 3; i <= sqrt(n); i = i+2){
        if(n%i == 0){
            if((i-1)%4 == 0){
                return true;
            }
            n /= i;
            while(n%i == 0){
                n/=i;
            }
        }
    }
    if( n > 2 ){
        if((n-1)%4 == 0){
            return true;
        }
    }
    return false;
}
void generatePythoPrime(){
    pythoPrimes.reserve(4790);
    for(int i = 5; i < 800; i+= 2){
        if((i-1)%4 == 0){
            if(Miller(i, 4)){
                pythoPrimes.push_back(i);
            }
        }
    }
}
int main(){
    int T;
    int n;
    generatePythoPrime();
    bool ans = false;
    getfast_int(T);
    for(int i = 0; i < 5000001;i++){
        memo[i] = -1;
    }
    while(T--){
        getfast_int(n);
        if(memo[n] != -1){
            ans = memo[n];
        }
        else{
            ans = isHypotenuse(n);
            memo[n] = ans;
        }
        if(ans){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}
