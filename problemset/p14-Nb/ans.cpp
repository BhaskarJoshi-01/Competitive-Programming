#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int x,y,z;cin>>x>>y>>z;
    int ans=0;
    for(int i=x;i<=y;i++){
        int dist_div = 0;
        int t = sqrt(i);
        if(t*t==i){
            t--;
            ++dist_div;
        }
        for(int j=1;j<=t;j++){
            if(i%j==0){
                dist_div+=2;
            }
        }
        if(dist_div<=z)++ans;
    }
    cout<<ans<<"\n";
}