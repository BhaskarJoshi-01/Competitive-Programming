#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int sum = 0;
        for(int i=0;i<k;i++){
            sum += arr[i];
        }
        int ans = sum;
        for(int i=k;i<n;i++){
            sum = sum + arr[i] - arr[i-k];
            ans = min(ans,sum);
        }
        cout<<ans<<"\n";
    }
}