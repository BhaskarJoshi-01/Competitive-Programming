#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000000007

long long modulo_expo(long long a, long long b){
    long long res = 1;
    a = a%m;
    while(b){
        if(b&1){
            res = (res*a)%m;
        }
        a = (a*a)%m;
        b>>=1;
    }
    return res;
}

long long modinv(long long a){
    return modulo_expo(a,m-2);
}

long long sum(long long l){
    long long temp =  ((((l%m)*((l+1)%m))%m)*modinv(2))%m;
    return temp;
}

long long int divisorsum(long long int x){
    long long ans = 0;
    long long l = 1;
    while(l<=x){
        long long k = x/l;
        long long r = x/k;
        k%=m;
        ans = (ans + (((sum(r)-sum(l-1))%m)*k)%m)%m;
        l = r+1;
    }
    return (ans+m)%m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;cin>>n;
    cout<<divisorsum(n)<<"\n";
}