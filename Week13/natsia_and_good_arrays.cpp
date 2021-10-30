#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int sindex = 0,k=0;
        long int arr[n];
        long int brr[n][4];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i] < arr[sindex]){
                sindex = i;
            }
        }
        for(int i = 0;i < n; i++){
            if(i == sindex){
                continue;
            }
            brr[k][0] = sindex;
            brr[k][1] = i;
            brr[k][2] = arr[sindex];
            brr[k][3] = arr[sindex] + abs(i-sindex);
            k++;
        }
        cout<<k<<endl;
        if(k>0){
            for(int i=0;i<k;i++){
                cout<<brr[i][0]+1 << " " << brr[i][1]+1 << " " << brr[i][2] << " " << brr[i][3] << endl;
            }
        }
    }
}