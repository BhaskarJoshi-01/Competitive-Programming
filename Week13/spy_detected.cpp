#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n],brr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) brr[i] = arr[i];
        sort(brr,brr+n);
        int mid = brr[(int)n/2];
        int spy = mid == brr[0] ? brr[n-1] : brr[0];
        for(int i=0;i<n;i++){
            if(arr[i] == spy){
                cout<<i+1<<endl;
                break;
            }
        }
    }
}