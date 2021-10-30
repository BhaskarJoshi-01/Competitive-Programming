#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        int ans = 2;
        if(is_sorted(arr,arr+n)){
            ans = 0;
        }
        else if(arr[0] == 1 || arr[n-1] == n){
            ans = 1;
        }
        else if(arr[0] == n && arr[n-1] == 1){
            ans = 3;
        }
        cout<<ans<<endl;
    }
}