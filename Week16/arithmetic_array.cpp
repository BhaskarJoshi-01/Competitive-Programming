#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n];
        int mean = 0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mean += arr[i];
        }
        int temp = mean-n;
        if(temp >= 0){
            cout<<temp<<"\n";
            continue;
        }
        if(temp < 0){
            cout<<1<<"\n";
        }
    }
}