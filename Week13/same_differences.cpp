#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            arr[i] = temp - i;
        }
        sort(arr,arr+n);
        long long int temp = 0, ans = 0, i = 0;
        while(i<n){
            temp = arr[i];
            i++;
            int k = 1;
            while(i<n && arr[i] == temp){
                k++;
                i++;
            }
            ans += ((long long int)k*(k-1))>>1;
        }
        cout<<ans<<endl;
    }
}
