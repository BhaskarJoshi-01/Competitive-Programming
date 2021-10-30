#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char arr[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int t;
    cin>>t;
    while(t--){
        int touched[26] = {0};
        int n,fg = 1;
        cin >> n;
        char temp[n];
        for(int i=0;i<n;i++){
            cin >> temp[i];
            for(int j=0;j<26;j++){
                if(temp[i] == arr[j]){
                    if(i>0 && temp[i]!=temp[i-1] && touched[j] == 1){
                        fg = 0;
                    }
                    else {
                        touched[j] = 1;
                    } 
                }
            }
        }
        fg?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
}