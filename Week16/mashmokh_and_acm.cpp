#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
#define ll long long
#define ld long double

int ret_div(int n){
    int ans = 0;
    int temp = sqrt(n);
    if(temp*temp == n){
        temp--;
        ans++;
    }
    for(int i=1;i<=temp;i++){
        if(n%i==0) ans+=2;
    }
    return ans;
}

ll modulo_expo(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = (res*a)%m;
        b = b>>1;
        a = (a*a)%m;
    }
    return res;
}

ll ret_comb(int n,int r){
    ll temp = n-r;
    ll ans = 1;
    for(int i=1;i<=r;i++){
        ans = (((ans*(temp+i))%m)*(modulo_expo(i,m-2)))%m;
    }
    return ans;
}

int main(){
    int n,k;cin>>n>>k;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        int div = ret_div(i);
        int n = k+div-1;
        int r = min(k,div-1);
        cout<<"i : "<< i << " \n";
        cout<<"div : "<<div<<"\n";
        cout<<"ret_comb(n,r) : "<<ret_comb(n,r)<<"\n";
        cout<<"ret_comb(n,r) - div + 1 : "<<ret_comb(n,r) - div + 1 <<"\n";
        ans = (ans + ret_comb(n,r) - div + 1 + m)%m;
    }
    cout<<ans<<"\n";
}