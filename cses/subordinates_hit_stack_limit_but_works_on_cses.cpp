#include<bits/stdc++.h>
using namespace std;
int dp[200000];

int calcu(vector<vector<int>>&edge,int target){
    if(dp[target]>0) return dp[target];
    dp[target]=1;
    for(int i=0;i<edge[target].size();i++){
        if(dp[edge[target][i]] >0) dp[target] += dp[edge[target][i]];
        else dp[target] += calcu(edge,edge[target][i]);
    }
    return dp[target];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<vector<int>> edge(n,vector<int>());
    for(int i=1;i<n;i++){
        int temp;cin>>temp;
        edge[temp-1].push_back(i);
    }
    for(int i=0;i<n;i++){
        if(edge[i].size()==0) dp[i]=1;
    }
    calcu(edge,0);
    for(int i=0;i<n;i++)cout<<(dp[i]-1)<<" ";
    cout<<"\n";
}