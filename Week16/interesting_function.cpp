#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll modulo_expo(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a;
        b = b>>1;
        a = a*a;
    }
    return res;
}

int main(){
    int t;cin>>t;
    while (t--){
        ll l,r;cin>>l>>r;
        ll temp1=0,temp2=0;
        for(int i=0;i<11;i++){
            temp1 += l/modulo_expo(10,i);
            temp2 += r/modulo_expo(10,i);
        }
        cout<<temp2-temp1<<"\n";
    }
}