#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;cin>>t;
    while(t--){
        int n,a,b;cin>>n>>a>>b;
        if(a == 1 || b == 1 || n==1){
            if(n==1) cout<<"YES\n";
            else if(b==1){
                cout<<"YES\n";
            }
            else if(a == 1){
                if((n-1)%b == 0) cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
        else{
            if((n-1)%b == 0){
                cout<<"YES\n";
                continue;
            }
            else{
                ll arr[33]={0};
                int i=0;
                ll temp1 = n;
                ll p = pow(a,i);
                ll k = temp1/p;
                bool fl = false;
                while(temp1/p != 0){
                    arr[i] = temp1%p;
                    if(arr[i]>0 && arr[i]%p!=0){
                        if(arr[i]%p == 1 && !fl){
                            fl = true;
                            ll tk = pow(a,i+1);
                            if(temp1/p!=0){
                                cout<<"NO\n";
                            }
                            else{
                                cout<<"YES\n";
                            }
                        }
                        else{
                            cout<<"NO\n";
                            break;
                        }
                    }
                    else{
                        if(arr[i]>0 && fl){
                            cout<<"NO\n";
                            break;
                        }
                    }
                    // arr[i]=temp1%p;
                    temp1 = temp1/p;
                    p = pow(a,++i);
                }
                cout<<"YES\n";
            }
        }
    }
}
