#include <iostream>
using namespace std;
#define ll long long int
#define min3(x,y,z) min(x,min(y,z))
int main()
{
    string sn,sm;
    cin >> sn >> sm;
    ll n=sn.length(),m=sm.length();
    ll dp[n+1][m+1];
    for(int i=0;i<n+1;i++) dp[i][0]=i;
    for(int i=0;i<m+1;i++) dp[0][i]=i;
 
    for(int i=1;i<n+1;i++)
        for(int j=1;j<m+1;j++)
            dp[i][j] = min3(dp[i-1][j-1]+((sn[i-1]==sm[j-1])?0:1),dp[i-1][j]+1,1+dp[i][j-1]);
 
    cout << dp[n][m] <<  endl;
    return 0;
}
