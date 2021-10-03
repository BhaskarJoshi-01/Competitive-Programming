#include <iostream>
using namespace std;
int main()
{
    int n,arr[101],sum=0,count=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        sum+=arr[i];
    }
    int dp[sum+1]={0};
    dp[0]=1;
    for(int i=0;i<n;i++)
        for(int j=sum;j>=0;j--)
            if(dp[j]) dp[j+arr[i]]=1;
    for(int i=1;i<=sum;i++)
        if(dp[i]) count++;
    cout << count << endl;
    for(int i=1;i<=sum;i++)
        if(dp[i]) cout << i << " ";
    cout << endl;
    return 0;
}
