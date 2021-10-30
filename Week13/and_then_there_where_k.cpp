#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k=0;
        // cout << 100;
        while(n>0){
            k++;
            n = n/2;
        }
        long int ans = 0;
        for(int i=0;i<k-1;i++){
            ans += pow(2,i);
        }
        cout<<ans<<endl;
    }
}