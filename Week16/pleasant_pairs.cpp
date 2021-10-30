#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[2*n+2]={0};
        int temp;
        for(int i=0;i<n;i++) {
            cin>>temp;
            arr[temp] = i+1;
        }
        int ans = 0,temp2 = 2*n;
        for(int i=1;i<temp2;i++){
            int root = sqrt(i);
            if(root*root == i){
                root--;
            }
            for(int j=1;j<=root;j++){
                if(i%j==0){
                    int tem = i/j;
                    if(arr[j] && arr[tem] && (arr[j]+arr[tem] == i)){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}