#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int find_element(vector<int> arr,int n,int num){
    int start = 0;
    int end = n-1;
    while(start <= end){
        int temp = (start+end)/2;
        if(num == arr[temp]){
            return temp;
        }
        else if(num > arr[temp]){
            start = temp + 1;
        }
        else{
            end = temp - 1;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<bool>visited(n+1,false);
        vector<int>arr;
        for(int i=0;i<n;i++){
            int temp;cin>>temp;
            arr.push_back(temp);
        }
        vector<int>ans;
        int k = n;
        int end = n;
        for(int i=n-1;i>=0;i--){
            if(k==arr[i]){
                int j=i;
                while(j<end){
                    ans.push_back(arr[j]);
                    visited[arr[j]] = true;
                    j++;
                }
                end = i;
                j = k;
                while(visited[j])j--;
                k = j;
            }
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}