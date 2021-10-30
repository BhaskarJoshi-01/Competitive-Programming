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

int visited[1000006];

void divisors(int x){
    int val = sqrt(x);
    // deb(val);
    if(val*val == x){
        visited[val]++;
        val--;
    }
    // deb(ans,val);
    for(int i=1;i<=val;i++){
        if((x%i) == 0){
            visited[i]++;
            visited[x/i]++;
        }
        // deb(x,val,i,x/i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    while(n--){
        int x;
        cin>>x;
        divisors(x);
    }
    for(int i=1000005;i>=0;i--){
        if(visited[i]>1){
            cout<<i<<"\n";
            break;
        }
    }
}