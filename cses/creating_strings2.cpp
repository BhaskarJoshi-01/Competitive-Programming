#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
typedef long long ll;

int alpha[30];
ll fact[1000007];

ll modulo_expo(ll a,ll b,ll mod){
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
        fact[i] = (fact[i-1]*i)%m;
    }
    string s;cin>>s;
    for(int i=0;i<s.size();i++){
        alpha[s[i]-'a']++;
    }
    ll ans = fact[s.size()];
    for(int i=0;i<26;i++){
        ans = (ans*modulo_expo(fact[alpha[i]],m-2,m))%m;
    }
    printf("%lld\n",ans);
}