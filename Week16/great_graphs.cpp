#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n];
        ll sum=0;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            sum+=arr[i];
        }
        sort(arr,arr+n);
        ll ans = 0,temp = 0;
        for(int i=0;i<n-1;i++){
            sum = sum - (arr[i]-temp)*(n-i);
            ans += sum;
            temp = arr[i];
        }
        for(int i=1;i<n;i++){
            ans -= arr[i]-arr[i-1];
        }
        printf("%lld\n",-1*ans);
    }
}