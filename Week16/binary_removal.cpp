#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        bool flag = true;
        int val = -1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1] && s[i] == '1'){
                val = i;
            }
            if(s[i]==s[i+1] && s[i]=='0' && val>=0){
                flag = false;
                break;
            }
        }
        if(flag) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}