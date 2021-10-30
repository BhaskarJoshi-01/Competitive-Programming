#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    // if(n==1)printf("1\n");
    // else if(n<4) cout<<"NO SOLUTION\n";
    // else{
    //     int t=(n/2)+1,g=1;
    //     for(int i=0;i<n;i++){
    //         if(i&1)printf("%d ",g++);
    //         else printf("%d ",t++);
    //     }
    //     printf("\n");
    // }
    long long temp = pow(n,m);
    cout<<temp<<"\n";
}