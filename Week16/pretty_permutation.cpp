#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while (t--){
        int n;cin>>n;
        if(n&1){
            for(int i=1;i<n-2;i+=2){
                cout<<i+1<<" "<<i<<" ";
            }
            cout<<n-1<<" "<<n<<" "<<n-2;
            cout<<"\n";
        }
        else{
            for(int i=1;i<n;i+=2){
                cout<<i+1<<" "<<i<<" ";
            }
            cout<<"\n";
        }
    }
    
}