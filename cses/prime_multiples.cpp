#include<bits/stdc++.h>
using namespace std;

long long int comb(vector<long long int>primes ,long long int N, long long int K,long long int X){
    long long int temp = 0;
    string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's
    do {
        long double temp1= (long double)X;
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if(bitmask[i]) {
                temp1 = temp1/primes[i];
                // cout<<" "<<primes[i];
            }
        }
        // cout<<"\n";
        temp += (long long int)temp1;
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
    return temp;
}

int main(){
    long long int n,k;cin>>n>>k;
    vector<long long int>primes(k,0);
    for(int i=0;i<k;i++) cin>>primes[i];
    long long int ans = 0;
    for(int i=1;i<=k;i++){
        if(i%2){
            ans += comb(primes,k,i,n);
        }
        else{
            ans -= comb(primes,k,i,n);
        }
    }
    printf("%lld\n",ans);
}