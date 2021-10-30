#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin>>t;
    while(t--){
        long long int A,B,z;
        cin>>A;
        cin>>B;
        if(B==1){
            cout << "NO" << endl;
            continue;
        }
        else if(B==2){
            z = 4;
        }
        else{
            z = B;
        }
        cout << "YES" << endl << A << " " << (z-1)*A << " " << z*A << endl;
    }
}