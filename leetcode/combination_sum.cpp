#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr,int target,int sum,vector<int> ans,vector<vector<int>>&val,int st){
    int n = arr.size();
    for(int i=st;i<n;i++){
        int temp = sum+arr[i];
        if(temp>target) continue;
        ans.push_back(arr[i]);
        if(temp == target){
            val.push_back(ans);
            ans.pop_back();
            continue;
        }
        solve(arr,target,temp,ans,val,i);
        ans.pop_back();
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<int> arr;
        for(int i=0;i<n;i++) {
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        vector<int> k;
        vector<vector<int>>val;
        solve(arr,m,0,k,val,0);
        auto ans = val;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<" ";
            cout<<"\n";
        }
    }
}