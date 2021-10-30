#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int> arr){
    int s=INT_MAX,b=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]<s) s = arr[i];
        if(arr[i]>b) b = arr[i];
    }
    int s1=INT_MAX,s2=INT_MIN,b1=INT_MAX,b2=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i] == s){
            s1 = min(s1,i);
        }
        if(arr[i] == b){
            b1 = min(b1,i);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i] == s){
            s2 = max(s2,i);
        }
        if(arr[i] == b){
            b2 = max(b2,i);
        }
    }
    return min(s1,n-s2) + min(b1,n-b2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>arr(n,0);
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<solve(n,arr)<<"\n";
    }
}