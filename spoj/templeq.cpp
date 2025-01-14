#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
#define mp make_pair
#define pb push_back
#define author rajat1603
#define mod 1000000007
#define N 100011
int bit[N]={0};
int n;
void update(int idx,int val){
    while(idx <= n){
        bit[idx] += val;
        idx += idx& - idx;
    }
}
int query(int idx){
    int sum=0;
    while(idx){
        sum +=bit[idx];
        idx&=idx-1;
    }
    return sum;
}
int lowerbound(int val){
    int l=1,r=n;
    if(query(r)<val){
        return n+1;
    }
    while(l<r){
        int mid = (l+r)>>1;
        if(query(mid)>=val){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return l;
}
int q;
pair<int,int> p[N];
int ind[N];
int pos[N];
int main(){
	n=scan(),q=scan();
    for(int i=1;i<=n;++i){
        p[i].first=scan();
        p[i].second=i;
    }
    sort(p+1,p+1+n);
    for(int i=1;i<=n;++i){
        ind[p[i].second]=i;
        pos[i]=p[i].second;
    }
    p[0].first=0;
    for(int i=1;i<=n;++i){
        update(i,p[i].first-p[i-1].first);
    }
    while(q--){
        int type=scan(),x=scan();
        if(type==1){
            int y = query(ind[x]);
            int z = pos[lowerbound(y+1)-1];
            swap(ind[x],ind[z]);
            pos[ind[x]]=x;
            pos[ind[z]]=z;
            update(ind[x],1);
            update(ind[x]+1,-1);
        }
        else if(type==2){
            printf("%d\n",n+1-lowerbound(x));
        }
        else{
            update(lowerbound(x),-1);
        }
    }
} 

