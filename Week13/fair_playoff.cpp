#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int s1,s2,s3,s4;
        cin>>s1>>s2>>s3>>s4;
        int f1,f2,h1,h2;
        int arr[4] = {s1,s2,s3,s4};
        sort(arr,arr+4,greater<int>());
        h1 = arr[0];
        h2 = arr[1];
        f1 = max(s1,s2);
        f2 = max(s3,s4);
        if(( h1 == f1 && h2 == f2 )||( h2 == f1 && h1 == f2 )){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}