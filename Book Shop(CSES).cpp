#include <iostream>
using namespace std;
#define ll long long int
int main()
{
    ll n,x;
    cin >> n >> x;
    ll prices[n],pages[n];
    for(int i=0;i<2*n;i++)
    {
        if(i<n) cin >> prices[i];
        else cin >> pages[i-n];
    }
    ll dp[x+1]={0};
    for(ll i=0;i<n;i++)
        for(ll j=x;j>=0;j--)
            if(j+prices[i]<=x) dp[j+prices[i]]= max(dp[j+prices[i]],dp[j]+pages[i]);
    cout << dp[x] << endl;
 
    return 0;
}
