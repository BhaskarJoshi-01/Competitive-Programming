#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;cin>>t;
    while(t--){
        map<pair<int,int>,int> val;
        int n,d=0,k=0; string s; cin>>n>>s;
        int arr[n]={0};
        for(int i=0;i<s.size();i++){
            if(s[i]=='D') d++;
            else k++;
            int temp1 = d/__gcd(d,k);
            int temp2 = k/__gcd(d,k);
            arr[i] = ++val[make_pair(temp1,temp2)];
        }
        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        cout<<"\n";
    }
}