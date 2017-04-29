//Codechef | Medium | Pairwise and sum
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>
#define gc getchar_unlocked
void getfast_int(int &x){
    int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc()){};
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main(){
    std::vector<int> bits(31,0);
    long long sum = 0;
    int temp;
    int n;
    getfast_int(n);
    for(int i = 0;i<n;i++){
        getfast_int(temp);
        for(int i = 0; i < 31; i++){
            if(temp % 2 == 0);
            else{
                bits[i] += 1;
            }
            temp /= 2;
        }
    }
    for(int i = 0;i < 31;i++){
        sum += pow(2,i)*bits[i]*(bits[i]-1)/2;
    }
    printf("%lld\n", sum);
}
