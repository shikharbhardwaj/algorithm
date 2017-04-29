#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int n;
int filters[100002];
int dp[100002][1025];
int compute_ans(int i,int x) {
    if(i==n) {
        if(x==0)return 1;
        return 0;
    }
    int ans1,ans2,y = (filters[i])^x;
    if(dp[i+1][y] != -1) {
        ans1=dp[i+1][y];
    }
    else {
        ans1=dp[i+1][y]=compute_ans(i+1,y)%MOD;
    }
    if(dp[i+1][x]!=-1) {
        ans2=dp[i+1][x];
    }
    else {
        ans2=dp[i+1][x]=compute_ans(i+1,x)%MOD;
    }
    dp[i][x]=(ans1+ans2)%MOD;
    return dp[i][x] ;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        //to avoid working with strings i convert them into corresponding
        //binary numbers and then applying a filter is just an XOR operation
        //strtol takes care of converting the number 
        //bwb becomes 010 = 2
        //+-+ becomes 101 = 5
        char s[12];
        scanf("%s",s);
        for(int i=0;i<10;i++){s[i]=(s[i]=='w')?'1':'0';}
        int photo = strtol(s,NULL,2);
        scanf("%d",&n);
        // the most expensive step !
        for(int i=0;i<=n;i++)for(int j=0;j<=1024;++j)dp[i][j]=-1;
        for(int i=0;i<n;++i) {
            char x[12];
            scanf("%s",x);
            for(int i=0;i<10;++i){x[i]=(x[i]=='+')?'1':'0';}
            filters[i]=strtol(x,NULL,2);
        }
        printf("%d\n",compute_ans(0,photo));
    }
    return 0;
}
