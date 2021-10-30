#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n,k1,k2,w,b;cin>>n>>k1>>k2>>w>>b;
        bool flag = true;
        if(((k1+k2)/2)<w) flag = false;
        if((2*n-(k1+k2))/2<b) flag = false;
        if(flag){
            cout<<"Yes"<<"\n";
        }
        else cout<<"NO"<<"\n";
    }
}