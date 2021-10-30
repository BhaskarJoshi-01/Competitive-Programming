#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        long long y,x;cin>>y>>x;
        long long ans = 0;
        if(x==y) ans = (x*x)-x+1;
        else if(x>y) {
            if(x&1) ans = (x*x)-x+1+(x-y);
            else ans = (x*x)-x+1-(x-y);
        }
        else {
            if(y&1) ans = (y*y)-y+1-(y-x);
            else ans = (y*y)-y+1+(y-x);
        }
        cout<<ans<<"\n";
    }
}