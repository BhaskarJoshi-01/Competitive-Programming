#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll arr[3];
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr+0,arr+3);
    printf("%lld\n",arr[1]+arr[2]);
}