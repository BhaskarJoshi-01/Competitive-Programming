#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,maxi;cin>>n>>maxi;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int sum = 0;
        int k=0;
        for(int i=0;i<n;i++){
            sum = 0;
            int j=i;
            while(j<n && sum < maxi){
                sum += arr[j];
                if(sum<maxi){
                    k++;
                }
                j++;
            }
        }
        cout<<k<<"\n";
    }
}