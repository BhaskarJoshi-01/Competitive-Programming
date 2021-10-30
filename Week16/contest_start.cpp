#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;cin>>k;
    while(k--){
        long long int n,x,t; cin>>n>>x>>t;
        long long int ans = 0;
        long long int temp = t/x;
        ans += (min(n,temp)*min(n-1,(temp-1)))/2;
        ans += max((long long int)0,(n-temp))*temp;
        printf("%lld\n",ans);
    }
}