#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n],brr[n],k=0;
        for(int i=0;i<n;i++) brr[i] = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]&1){
                brr[k]=arr[i];
                k++;
            }
        }
        // cout<<"K : "<< k <<endl;
        // cout<<"N-K : "<< n-k <<endl;
        long int ans = k*(n-k);
        if(n-k>1){
            ans+=((n-k)*(n-k-1))/2;
        }
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                if(__gcd(brr[i],brr[j]) > 1){
                    // cout<<"Pairs : " <<  brr[i]<<" " << brr[j] << endl;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}