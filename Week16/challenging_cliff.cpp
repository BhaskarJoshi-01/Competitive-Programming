#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n],brr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long int temp = 1e12;
        int l1=0,l2=1;
        sort(arr,arr+n);
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1]) < temp){
                temp = abs(arr[i]-arr[i-1]);
                l1 = i-1;l2 = i;
            }
        }
        if(abs(arr[n-1]-arr[n-2]) == temp){
            l1 = n-2;l2 = n-1;
        }
        brr[0] = arr[l1];
        brr[n-1] = arr[l2];
        int k = 0;
        for(int i=l2+1;i<n;i++){
            brr[i-l2] = arr[i];
        }
        for(int i=0;i<l1;i++){
            brr[l2+i] = arr[i];
        }
        // swap(arr[0],arr[l1]);
        // swap(arr[n-1],arr[l2]);
        // sort(arr+1,arr+n-1);
        // if(n == 4){ 
        //     int temp = 0,temp1 = 0;
        //     for(int i=1;i<n;i++){
        //         if(arr[i]>=arr[i-1]){
        //             temp++;
        //         }
        //     }
        //     swap(arr[1],arr[2]);
        //     for(int i=1;i<n;i++){
        //         if(arr[i]>=arr[i-1]){
        //             temp1++;
        //         }
        //     }
        //     if(temp > temp1){
        //         swap(arr[1],arr[2]);
        //     }
        // }
        for(int i=0;i<n;i++){
            cout<<brr[i]<<" ";
        }
        cout<<"\n";
    }
}