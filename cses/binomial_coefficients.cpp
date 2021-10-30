#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll; 

ll fact[1000007];

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    for(int i=1;i<1000007;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    int t;cin>>t;
    while(t--){
        int n,r;cin>>n>>r;
        ll ans = (((fact[n]*modulo_expo(fact[r],mod-2))%mod)*(modulo_expo(fact[n-r],mod-2)))%mod;
        printf("%lld\n",ans);
    }
}