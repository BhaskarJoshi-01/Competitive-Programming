#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    char str1[n],str2[m];
    cin>>str1>>str2;
    int arr[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j == 0){
                arr[i][j] = 0;
            }
            else if(str1[i-1] == str2[j-1]){
                arr[i][j] = arr[i-1][j-1] + 1;
            }
            else{
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    cout<<n <<" " << m<<"\n";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<< arr[i][j] << " ";
        }
        cout<<"\n";
    }
}