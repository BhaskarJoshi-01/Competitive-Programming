#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main(){
    int n,k;cin>>n>>k;
    int temp = n/2;
    if(k<temp || (n<2 && k!=0)) cout<<"-1\n";
    else if(k == temp){
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    else{
        int temp1 = k - temp +1;
        cout<<temp1<<" "<<2*temp1<<" ";
        int d = 2*temp1 +1;
        for(int i=0;i<2*(temp-1);i++) cout<< d+i<<" ";
        if(n&1)cout<<d + 2*(temp-1)<<" ";
        cout<<"\n";
    }
}