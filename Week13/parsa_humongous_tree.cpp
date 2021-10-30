#include <bits/stdc++.h>
using namespace std;

#define ll long long int;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long int n;
        cin >> n;
        tuple <long long int,long long int> NonV[n];
        vector <int>edge[n];
        for(int i=0;i<n;i++){
            long long int temp1,temp2;
            cin>>temp1>>temp2;
            NonV[i] = tuple<long long int, long long int>(temp1,temp2);
        }
        for(int i=0;i<n-1;i++){
            long long int temp1,temp2;
            cin>>temp1>>temp2;
            edge[temp1].push_back(temp2);
            edge[temp2].push_back(temp1);
        }
    }
}