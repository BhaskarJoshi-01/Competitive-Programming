#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        ll p,a,b,c;cin>>p>>a>>b>>c;
        cout<<min({(a-p%a)%a,(b-p%b)%b,(c-p%c)%c})<<"\n";
    }
}