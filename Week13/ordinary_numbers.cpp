#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long int n;
        cin >> n;
        int power = 9, ans = 0;
        long int a = pow(10,power);
        while(n/a==0 && power>0){
            power--;
            a = pow(10,power);
        }
        long int div = n/a;
        long int residue = n%a, val = 0;
        ans += power*9 + div;
        while(power--){
            val += div*pow(10,power);
        }
        if(residue < val){
            ans--;
        }
        cout<<ans<<endl;
    }    
}