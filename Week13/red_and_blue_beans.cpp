#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int r,b,d,small,big;
        cin>>r>>b>>d;
        small = min(r,b);
        big = r+b - 2*small;
        if(d == 0){
            if(r == b){
                cout << "YES" << endl;
            }
            else{
                cout <<"NO"<<endl;
            }
        }
        else{
            if(ceil((float)big/small) <= d){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
}