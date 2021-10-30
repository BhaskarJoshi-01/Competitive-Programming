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
        long int arr[n];
        long long int brr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int k=0,i=0,j=0;
        for(i=0;i<n;i++){
            if(arr[i]<=0){
                if(i!=n-1){
                    brr[j] = abs(arr[i+1]-arr[i]);
                    j++;
                }
                k++;
            }
        }
        sort(brr,brr+j);
        if(k<n){
            if(j>0 && brr[0]>=arr[k]){
                k++;
            }
            else{
                if(j==0){
                    k++;
                }
            }
        }
        cout <<k <<endl;
    }
}