#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=250250;
const ll M=10000000000000000LL;
const ll mod=250;
ll a[N+1],dp[2][mod];

ll modpow(ll a, ll b){
    ll x=1;
    while(b){
        if(b&1) x=x*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return x;
}

int main(){
    for(int i=1;i<=N;i++) a[i]=modpow(i,i);
    memset(dp,0,2*mod*sizeof(ll));
    dp[0][0]=dp[1][0]=1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<mod;j++) dp[0][(a[i]+j)%mod]=(dp[0][(a[i]+j)%mod]+dp[1][j])%M;
        memcpy(dp[1],dp[0],mod*sizeof(ll));
    }
    cout << (dp[0][0] ? dp[0][0]-1 : M-1);
}
//output: 1425480602091519
