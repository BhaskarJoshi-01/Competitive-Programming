#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main(){
    int n,a,b;cin>>n>>a>>b;
    ll arr[n]={0};
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        ll k = ((ld)temp*a)/b;
        arr[i] = (ld)temp - ((ld)k*b)/a;
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"\n";
}