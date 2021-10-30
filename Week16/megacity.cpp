#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,s;cin>>n>>s;
    int temp1,temp2,temp3,temp4=s;
    vector<pair<long double,int>>val;
    for(int i=0;i<n;i++){
        cin>>temp1>>temp2>>temp3;
        temp4 += temp3;
        val.push_back(make_pair(sqrt(temp1*temp1 + temp2*temp2),temp3));
    }
    if(temp4 < 1000000){
        cout<<"-1\n";
        return 0;
    }
    sort(val.begin(),val.end());
    // for(int i=0;i<val.size();i++){
        // cout<<val[i].first<<" "<<val[i].second<<"\n";
    // }
    int i=0;
    while(s<1000000){
        s += val[i].second;
        i++;
    }
    printf("%0.7Lf\n",val[i-1].first);
    // cout<<val[i-1].first<<"\n";
}