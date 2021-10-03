#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define ll long long int
#define PI pair<pair<int,int>,int>
#define VPI vector<PI>
#define a(PI) PI.first.first
#define b(PI) PI.first.second
#define r(PI) PI.second
int main()
{
    ll n,day_num=-1;
    cin >> n;
    VPI PR;
    map<ll,ll> day;
    for(ll i=0;i<n;i++)
    {
        ll x,y,z;
        cin >> x >> y >> z;
        PR.push_back({{x,y+1},z});
        day[x];
        day[y+1];
    }
    for(auto it=day.begin();it!=day.end();it++) (*it).second = ++day_num;
 
    vector<vector<pair<ll,ll>>> completed(day_num+1);
    for(int i=0;i<n;i++) completed[day[b(PR[i])]].emplace_back( day[a(PR[i])],r(PR[i]) );
 
    ll dp[day_num+1]={0};     
    for(ll i=0;i<=day_num;i++)
    {
        if(i) dp[i]=dp[i-1];
        for(auto it:completed[i]) dp[i]=max(dp[i],it.second+dp[it.first]);
    }
    cout << dp[day_num] << endl;
    return 0;
}
