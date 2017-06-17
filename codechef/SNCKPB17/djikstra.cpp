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
	short t;
	ll n,m,a[501][501],max_val,dist[501][501],timer;
	cin>>t;
	while(t--){
		cin>>n>>m;
		set <pair<ll,pair<ll,ll>>> s;
		max_val = 0;
		FOR(i,n){
			FOR(j,m){
				cin>>a[i][j];
				if(a[i][j] > max_val)
					max_val = a[i][j];
			}
		}
		FOR(i,n){
			FOR(j,m){
				if(a[i][j] == max_val){
					dist[i][j] = 0;
					s.insert(mp(0,mp(i,j)));
				}
				else
					dist[i][j] = 99999999999999999;
			}
		}
		while(!s.empty()){
			auto x_it = s.begin();
			auto x = *x_it;
			i = x.second.first;
			j = x.second.second;
			timer = x.first;
			s.erase(x_it);
			if(i > 0 && dist[i - 1][j] > timer + 1){
				dist[i - 1][j] = min(dist[i - 1][j], timer + 1);
				s.insert(mp(dist[i - 1][j], mp(i - 1, j)));
			}
			if(i != n - 1 && dist[i + 1][j] > timer + 1){
				dist[i + 1][j] = min(dist[i + 1][j] + 1, timer + 1); 
				s.insert(mp(dist[i + 1][j], mp(i + 1, j)));
			}
			if(j > 0 && dist[i][j - 1] > timer + 1){
				dist[i][j - 1] = min(dist[i][j - 1], timer + 1);
				s.insert(mp(dist[i][j - 1], mp(i, j - 1)));
			}
			if(j != m - 1 && dist[i][j + 1] > timer	+ 1){
				dist[i][j + 1] = min(dist[i][j + 1], timer + 1);
				s.insert(mp(dist[i][j + 1], mp(i, j + 1)));
			}
			if(i > 0 && j > 0 && dist[i - 1][j - 1] > timer + 1){
				dist[i - 1][j - 1] = min(dist[i - 1][j - 1], timer + 1);
				s.insert(mp(dist[i - 1][j - 1], mp(i - 1, j - 1)));
			}
			if(i > 0 && j != m - 1 && dist[i - 1][j + 1] > timer + 1){
				dist[i - 1][j + 1] = min(dist[i - 1][j + 1], timer + 1);
				s.insert(mp(dist[i - 1][j + 1], mp(i - 1, j + 1)));
			}
			if(i != n - 1 && j > 0 && dist[i + 1][j - 1] > timer + 1){
				dist[i + 1][j - 1] = min(dist[i + 1][j - 1], timer + 1);
				s.insert(mp(dist[i + 1][j - 1], mp(i + 1, j - 1)));
			}
			if(i != n - 1 && j != m - 1 && dist[i + 1][j + 1] > timer + 1){
				dist[i + 1][j + 1] = min(dist[i + 1][j + 1], timer + 1);
				s.insert(mp(dist[i + 1][j + 1], mp(i + 1, j + 1)));
			}
		}
		ll ans = 0;
		FOR(i,n){
			FOR(j,m){
				ans = max(ans,dist[i][j]);
			}
		}
		cout<<ans<<endl;
	}
}