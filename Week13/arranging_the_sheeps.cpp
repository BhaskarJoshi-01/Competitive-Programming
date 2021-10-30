#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,sheeps=0;
        cin>>n;
        char str[n];
        cin>>str;
        int arr[n];
        for(int i=0;i<n;i++){
            if(str[i] == '*'){
                arr[sheeps] = i;
                sheeps++;
            }
        }
        int mid = sheeps/2;
        long long int ans = 0;
        for(int i=0;i<sheeps;i++){
            ans += abs(arr[mid] - arr[i] + i - mid);
        }
        cout << ans <<endl;
    }
}