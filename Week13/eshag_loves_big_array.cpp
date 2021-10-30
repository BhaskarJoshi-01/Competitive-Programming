#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int temp = arr[0];
        int i=0;
        for(i=0;i<n;i++){
            if(arr[i]!=temp){
                break;
            }
        }
        cout << n-i <<endl;
    }
}