#include <bits/stdc++.h>
using namespace std;

#define ll long long int;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int xa,xb,Xa,Xb;
        cin>>xa>>xb>>Xa>>Xb;
        int ans = ceil((float)Xa/xa) + ceil((float)Xb/xb);
        cout<<ans<<endl;
    }
}