#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#define gc getchar_unlocked
int getfast_int(){
	int c = gc();
	int x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = gc()){}
		if(c=='-') {neg=1;c=gc();}
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
		if(neg) x=-x;
    return x;
}
using namespace std;
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
    unsigned int i, last = sqrt(x);
    for (i = 0; i < len && numbers[i] <= last; i++)
    {
        if (!(x % numbers[i])) 
            return 0; 
    }
    return 1;
}
int factors[105];
std::map<int, int> factorFreq;
void fillFreq(int factor){
    if(factor % 2 == 0){
        if(factorFreq.find(2) == factorFreq.end()){
            factorFreq[2] = 1;
            factor /= 2;
        }
        while( factor % 2 == 0 ){
            factorFreq[2] += 1;
            factor /= 2;
        }
    }
    for(int i = 3; i <= sqrt(factor); i+=2){
        if(factor % i == 0){
            if(factorFreq.find(i) == factorFreq.end()){
                factorFreq[i] = 1;
                factor /= i;
            }
            while(factor % i == 0){
                factorFreq[i] += 1;
                factor /= i;
            }
        }
    }
    if( factor > 2 ){
        if( factorFreq.find(factor) == factorFreq.end() ){
            factorFreq[factor] = 1;
        }
        else{
            factorFreq[factor]++;
        }
    }
}
int main(){
    int T;
    int N;
    T = getfast_int();
    while(T--){
        N = getfast_int();
        for(int i = 0; i < N; i++){
            factors[i] = getfast_int();
            fillFreq(factors[i]);
        }
        //Now all prime factors of 
        //the resultant number have been
        //recorded in the frequency table
    }
}
