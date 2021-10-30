#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr,int target,int sum,vector<int> ans,vector<vector<int>>&val,int st){
    int a = arr[st];
    for(int i=st;i<arr.size();i++){
        int temp = sum+arr[i];
        if(temp>target) break;
        if(i>st && arr[i] == a) continue;
        else a = arr[i];
        ans.push_back(arr[i]);
        if(temp == target ){
            val.push_back(ans);
            ans.pop_back();
        }
        else{
            solve(arr,target,temp,ans,val,i+1);
            ans.pop_back();
        }
    }
}

vector<vector<int>> res;
void help(vector<int> v, vector<int> & c , int sum , int tar, int beg){
    if(sum == tar){
        res.push_back(v);
        return;
    }
    if(sum > tar || beg >= c.size())
        return ;
    
    int a = c[beg];
    for(int i = beg; i<c.size(); i++){
        if(sum+c[i] > tar)
            break;
        if(i>beg && c[i] == a)
            continue;
        else
            a = c[i];
        v.push_back(c[i]);
        help(v,c,sum+c[i],tar,i+1);
        v.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<int> arr;
        for(int i=0;i<n;i++) {
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        sort(arr.begin(),arr.end());
        // vector<int> v;
        // help(v,arr,0,m,0);
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