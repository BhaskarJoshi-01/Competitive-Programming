#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    int arr[n]={0};
    int k=0;
    for(int i=0;i<n;i++){
        if(s[i]=='X'){
            arr[i] = 1;
            k++;
        }
    }
    if(k==(n/2)){
        cout<<"0\n";
        cout<<s<<"\n";
    }
    else if(k<(n/2)){
        int temp = (n/2)-k;
        cout<<temp<<"\n";
        for(int i=0;i<n;i++){
            if(s[i]=='x' && temp){
                s[i] = 'X';
                temp--;
            }
        }
        cout<<s<<"\n";
    }
    else if(k>n/2){
        int temp = k-(n/2);
        cout<<temp<<"\n";
        for(int i=0;i<n;i++){
            if(s[i]=='X' && temp){
                s[i]='x';
                temp--;
            }
        }
        cout<<s<<"\n";
    }
}