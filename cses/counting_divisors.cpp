#include<bits/stdc++.h>
using namespace std;
// #define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
// template<typename ...Args>
// void logger(string vars, Args&&... values) {
//     cout << vars << " = ";
//     string delim = "";
//     (..., (cout << delim << values, delim = ", "));
//     cout<<"\n";
// }

int divisors(int x){
    int val = sqrt(x);
    int ans = 0;
    // deb(val);
    if(val*val == x){
        ans++;
        val--;
    }
    // deb(ans,val);
    for(int i=1;i<=val;i++){
        if((x%i) == 0){
            ans += 2;
        }
        // deb(ans,val,i);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        cout<<divisors(x)<<"\n";
    }
}