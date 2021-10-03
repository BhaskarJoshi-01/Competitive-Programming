#include <iostream>
using namespace std;
#define ll long long int
 
int main()
{
    ll n;
    cin >> n;
    ll dp[n][n],arr[n],sum=0;
    for(ll i=0;i<n;i++) cin >> arr[i];
    for(int i=n-1;i>=0;i--)
    {
        sum+=arr[i];
        dp[i][i]=arr[i];
        for(int j=i+1;j<n;j++)
            dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
    }
 
    cout << (sum+dp[0][n-1])/2 << endl;
    return 0;
}
