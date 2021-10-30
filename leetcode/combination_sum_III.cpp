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

vector<vector<int>> ans;
void sol(int k,int n,vector<int>a,int sum,int st){
    if(a.size()==k && sum == n){
        ans.push_back(a);
        return;
    }
    if(a.size() == k) return;
    for(int i=st;i<10;i++){
        if(sum+i>n) break;
        else{
            a.push_back(i);
            sol(k,n,a,sum+i,i+1);
            a.pop_back();
        }
    }
    return;
}

int main(){
    int k,n;cin>>k>>n;
    vector<int>a;
    sol(k,n,a,0,1);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
}