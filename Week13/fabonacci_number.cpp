#include <bits/stdc++.h>
using namespace std;

long long int fabonacci(long long int n){
    if(n <= 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return fabonacci(n-1) + fabonacci(n-2);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        cout << fabonacci(n)<<endl;
    }
}