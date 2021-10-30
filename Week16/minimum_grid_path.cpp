#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        long long ans=0;
        vector<long long>arr1,arr2;
        for(int i=0;i<n;i++){
            long long temp;cin>>temp;
            if(i&1) arr1.push_back(temp);
            else arr2.push_back(temp);
        }
        long long cur=arr1[0]*n,min=arr1[0]*n,min_val=arr1[0];
        for(int i=1;i<arr1.size();i++){
            if(arr1[i]<min_val){
                cur += -(n-i)*min_val + arr1[i]*(n-i); 
                min_val = arr1[i];
            }
            else{
                cur += -min_val + arr1[i];
            }
            if(cur<min){
                min = cur;
            }
        }
        ans += min;
        cur=arr2[0]*n,min=arr2[0]*n,min_val=arr2[0];
        for(int i=1;i<arr2.size();i++){
            if(arr2[i]<min_val){
                cur += -(n-i)*min_val + arr2[i]*(n-i); 
                min_val = arr2[i];
            }
            else{
                cur += -min_val + arr2[i];
            }
            if(cur<min){
                min = cur;
            }
        }    
        ans += min;    
        printf("%lld\n",ans);
    }
}