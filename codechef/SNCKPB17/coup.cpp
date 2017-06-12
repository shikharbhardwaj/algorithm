#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif	

#define FOR(i,n) for(size_t i=0;i<n;++i)
#define FOR1(i,n) for(size_t i=1;i<=n;++i)
#define FORRange(i,a,b) for(size_t i=a;i<=b;++i)
#define endl '\n'
#define ll int64_t
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()

using namespace std;

template <class Number> Number gcd(Number a,Number b){return a==0?b:gcd(b%a,a);}
template <class Number> Number powermod(Number base,Number exponent,Number mod){Number result=1;while(exponent>0){if(exponent%2==1)result=(result*base)%mod;exponent=exponent>>1;base=(base*base)%mod;}return result;}
template <class Number> Number extendedEuclid(Number a, Number b, Number *x, Number *y){Number t,d; if (b == 0){*x=1;*y=0;return a;}d=extendedEuclid(b,a%b,x,y);t=*x;*x=*y;*y=t-(a/b)*(*y);return d;}
template <class Number> Number inversemod(Number a,Number n){Number x,y;extendedEuclid(a,n,&x,&y);return(x<0)?(x+n):x;}

/* Use this for timing purposes
auto time1 = chrono::steady_clock::now();
auto time2 = chrono::steady_clock::now();
cout<<chrono::duration_cast<chrono::microseconds>(time2 - time1).count(); 
*/
 
int main(){
	#ifndef ONLINE_JUDGE	
	freopen("in.txt", "r", stdin);	
	freopen("out.txt", "w", stdout);
	#endif
	ll i,j;
	ios::sync_with_stdio(false);	
	int t,n,n0,n1,ptr;
	char s[2][100005], S[2][100005];
	cin>>t;
	while(t--){
		cin>>n;
		n0 = n1 = 0;
		set <int> s0,s1;
		FOR(i,2){
			FOR(j,n){
				cin>>s[i][j];
				if(i==0 && s[i][j] == '*'){
					n0++;
					s0.insert(j);
				}
				if(i==1 && s[i][j] == '*'){
					s1.insert(j);
					n1++;
				}
			}
		}
		if(n0==0 && n1==0) cout<<"0\n";
		else if(n0==0 && n1!=0) cout<<n1-1<<endl;
		else if(n1==0 && n0!=0) cout<<n0-1<<endl;
		else{ptr = 0;
			for(j=0;j<n;j++){
				if(s[1][j] !='.'|| s[0][j] !='.'){
					S[0][ptr] = s[0][j]; 
					S[1][ptr] = s[1][j];
					ptr++;
				}
			}
			n = ptr;
			set <int> lines;
			FOR(j,n-1){
				if(S[0][j]=='*'&&S[0][j+1]=='*')
					lines.insert(j);
			}
			FOR(j,n-1){
				if(S[1][j]=='*'&&S[1][j+1]=='*')
					if(lines.find(j)==lines.end())
						lines.insert(j);
			}
			for(j=0;j<n-2;j++){
				if(S[0][j]=='*'&&S[1][j]=='.')
					if(S[0][j+1]=='.'&&S[1][j+1]=='*')
						if(S[0][j+2]=='*'&&S[1][j+2]=='.'){
								if(lines.find(j)==lines.end())
								lines.insert(j+1);
						}
				if(S[1][j]=='*'&&S[0][j]=='.')
					if(S[1][j+1]=='.'&&S[0][j+1]=='*')
						if(S[1][j+2]=='*'&&S[0][j+2]=='.'){
								if(lines.find(j)==lines.end())
								lines.insert(j+1);
						}

							
							
			}
			cout<<lines.size()+1<<endl;
		}
	}
	return 0;
}