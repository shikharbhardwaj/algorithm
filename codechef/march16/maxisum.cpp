#include <iostream>
#include <vector>
#define getcx getchar_unlocked
#define getcx getchar_unlocked
inline void inp( int &n ){
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
inline void inp( long long &n ){
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
long long abs(long long a){
    if( a < 0 ){
        return (-1)*a;
    }
    return a;
}
int main(){
    int T, N, K;
    inp(T);
    while( T-- ){
        inp(N);inp(K);
        std::vector<long long> A(N);
        std::vector<long long> B(N);
        long long max_B, max_id, ans = 0;
        for( int i = 0; i < N; i++ ){
            inp(A[i]);
        }
        std::cin>>B[0];
        max_B = B[0];
        max_id = 0;
        ans += (A[0]*B[0]);
        for( int i = 1; i < N; i++ ){
            inp(B[i]);
            if( abs(B[i]) > abs(max_B)){
                max_B = B[i];
                max_id = i;
            }
            ans += (A[i]*B[i]);
        }
        ans -= (A[max_id] * B[max_id]);
        if( B[max_id] < 0){
            A[max_id] -= K;
        }
        else{
            A[max_id] += K;
        }
        ans += (A[max_id] * B[max_id]);
        printf("%lld\n", ans);
    }
}

