#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a =  *b;
    *b = temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin>>n; cin>>x;
        int arr[n],brr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        int temp = 0;
        for(int i=0;i<n;i++){
            temp += arr[i];
        }
        if(temp == x){
            cout << "NO" <<endl;
        }
        else{
            cout << "YES" << endl;
            for(int i=0;i<n;i++){
                if(x == arr[i]){
                    swap(arr[i+1],arr[i]);
                }
                cout << arr[i] << " ";
                x-= arr[i];
            }
            cout << endl;
        }
    }
}