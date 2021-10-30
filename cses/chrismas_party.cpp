#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
typedef long long ll;
int fac[1000007];
int inv[1000007];

ll modulo_expo(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = (res*a)%m;
        a = (a*a)%m;
        b = b>>1;
    }
    return res;
}

int main(){
    inv[0] = fac[0] = fac[1] = 1;
    for(int i=1;i<1000007;i++){
        fac[i] = ((ll)fac[i-1]*i)%m;
        inv[i] = modulo_expo(fac[i],m-2);
    }
    int n;cin>>n;
    ll ans = 1;
    for(int i=1;i<=n;i++){
        if(i&1) ans = (ans-inv[i]+m)%m;
        else (ans+=inv[i])%=m;
    }
    (ans*=fac[n])%=m;
    printf("%lld\n",ans);
}