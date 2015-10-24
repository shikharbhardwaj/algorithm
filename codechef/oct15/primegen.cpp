#include <cstdio>
#include <cmath>
#include<iostream>
#include <limits>
using namespace std;
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
int main(int argc, char **argv)
{
    unsigned long fno, sno;
    generate();
    argc++;
    int count = 0;
    fno = atoi(argv[1]);
    sno = atoi(argv[2]);
    if (fno == 1)
    {
        fno++;
    }
    while (fno <= sno)
    {
        if((fno-1)%4 == 0){
            if (process(fno))
            {
                count++;
            }
        }
        fno++;
    }
    cout<<"\nThe total number of primes : "<<count<<endl;
    return 0;
}


