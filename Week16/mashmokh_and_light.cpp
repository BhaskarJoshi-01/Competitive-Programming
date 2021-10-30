#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    int arr[n]={0};
    for(int i=0;i<m;i++){
        int temp;cin>>temp;
        int k = temp;
        while(arr[temp-1]==0 && temp <= n){
            arr[temp-1] = k;
            temp++;
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"\n";
}