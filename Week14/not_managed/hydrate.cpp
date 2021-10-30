#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if((c*d-b)<=0){
        cout<<-1<<"\n";
    }
    else{
        if(a%(c*d-b)==0){
            cout<<(a/(c*d-b))<<"\n";
        }
        else{
            cout<<(a/(c*d-b))+1<<"\n";
        }
    }
}