#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
typedef long long ll;

ll modulo_expo(ll a,ll b, ll p){
    ll res = 1;
    a%=p;
    while(b){
        if(b&1) res = (res*a)%p;
        b>>=1;
        a = (a*a)%p;
    }
    return res;
}

ll modinv(ll a, ll p){
    return modulo_expo(a,p-2,p);
}

void solve(vector<tuple<int,int>> A){
    ll num_div=1,sum_div=1,prod_div=1,num_div_prod=1;
    ll n=A.size();
    ll f=0,s =0;
    for(int i=0;i<n;i++){
        f = get<0>(A[i]);
        s = get<1>(A[i]);
        num_div = (num_div*((s+1)%m))%m;
        sum_div = (sum_div*((((modulo_expo(f,s+1,m)-1)%m)*(modinv(f-1,m)))%m))%m;
        prod_div = (modulo_expo(prod_div,s+1,m)*modulo_expo(modulo_expo(f,(((s)*(s+1))/2)%(m-1),m),num_div_prod,m))%m;
        num_div_prod = (num_div_prod*((s+1)%(m-1)))%(m-1);
    }
    cout<<num_div<<" "<<sum_div<<" "<<prod_div<<"\n";
}

int main(){
    int n;cin>>n;
    vector<tuple<int,int>>arr;
    while(n--){
        int temp1,temp2;cin>>temp1>>temp2;
        arr.push_back(make_tuple(temp1,temp2));
    }
    solve(arr);
}