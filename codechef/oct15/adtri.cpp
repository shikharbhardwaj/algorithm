#include <cstdio>
#include <cmath>
#include <vector>
//Final solution : OCT15/ADTRI
#define gc getchar_unlocked
int numbers[3500], len;     //For the prime test
int memo[5000001];          //Memo for the answers
std::vector<int> pythoPrimes;   //A list of primes of the form 4k+1
std::vector<int> notPythonPrimes;  //The complement of the above 
void getfast_int(int &x){
    int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline bool prime(int x){
    unsigned int i, last = sqrt(x);
    for (i = 2; i <= last; i++){
        if (!(x % i)){
            return 0;
        }
    }
    return 1;
}
void generate(){
    for (int i = 2; i < 32000; i++){
        if (prime(i)){
            numbers[len++] = i;
        }
    }
}
inline bool process(int x){    //Check if x is prime
    if(x == 1){
        return 0;
    }
    int i, last = sqrt(x);
    for (i = 0; i < len && numbers[i] <= last; i++){
        if (!(x % numbers[i])) 
            return 0; 
    }
    return 1;
}
bool isHypotenuse(int n){       //Can n be the hypotenuse of an integer right triangle?
    for(auto elem : notPythonPrimes){
        while( n%elem == 0 ){
            n /= elem;
        }
    }
    if(process(n)){
        if((n-1)%4 == 0){
            return true;
        }
        return false;
    }
    for(auto elem : pythoPrimes){
        if( n%elem == 0 ){
            return true;
        }
        if(elem > n){
            return false;
        }
    }
    for (int i = 5; i <= sqrt(n); i = i+2){ //Check if any prime factor of the number is of the form 4k+1
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
    for(int i = 5; i < 800; i+= 2){
        if((i-1)%4 == 0){
            if(process(i)){
                pythoPrimes.push_back(i);
            }
        }
    }
    notPythonPrimes.push_back(2);
    for(int i = 3; i < 100; i += 2){
        if((i-1)%4 != 0){
            if(process(i)){
                notPythonPrimes.push_back(i);
            }
        }
    }
}
int main(){
    int T;
    int n;
    generate();
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
