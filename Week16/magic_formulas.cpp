#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[1000050];
int main(){
    int n;cin>>n;
    ll temp1 = 0;
    for(int i=0;i<n;i++){
        ll temp;cin>>temp;
        temp1 = temp^temp1;
    }
    for(int i=0;i<n+10;i++){
        if(i==0){
            arr[0] = 0;
        }
        else{
            arr[i] = arr[i-1]^(i);
        }
    }
    ll temp2 = 0;
    for(int i=1;i<=n;i++){
        int k = n%i;
        if(k!=0){
            temp2 = temp2^arr[k];
        }
        if((n/i)%2){
            temp2 = temp2^arr[i-1];
        }
    }
    ll temp3 = temp1^temp2;
    cout<<temp3<<"\n";
}