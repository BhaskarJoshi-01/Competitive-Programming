#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int k=0;
        for(int i=0;i<2*n;i++){
            int temp;cin>>temp;
            if(temp&1)k++;
        }
        if(k==n) cout<<"YES\n";
        else cout<<"NO\n";
    }
}