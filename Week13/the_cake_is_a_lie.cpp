#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k,burles = 0;
        cin>>n>>m>>k;
        burles = n-1 + n*(m-1);
        burles == k ? cout<<"YES":cout<<"NO";
        cout<<endl;
    }
}