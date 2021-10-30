#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

ll modulo_expo(ll a,ll b){
    ll res = 1;
    if(a == 0 || a == 1) return a;
    while(b){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b = b>>1;
    }
    return res;
}

int main(){
    int n,m;cin>>n>>m;
    int t = min(n-1,m);
    ll ans = 1;
    int k = n+m-1-t;
    for(int i=1;i<=t;i++){
        ans = (((ans*(k+i))%mod)*modulo_expo(i,mod-2))%mod;
    }
    printf("%lld\n",ans);
}