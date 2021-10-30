#include<bits/stdc++.h>
using namespace std;
typedef long double ll;

ll get0(tuple<ll,ll> val){
    return get<0>(val);
}

ll get1(tuple<ll,ll> val){
    return get<1>(val);
}

int main(){
    int n;cin>>n;
    vector<tuple<ll,ll>>intervals;
    while(n--){
        int temp1;
        ll temp2,temp3;
        cin>>temp1>>temp2>>temp3;
        if(temp1==1){
            intervals.push_back(make_tuple(temp2,temp3));
        }
        if(temp1 == 2){
            intervals.push_back(make_tuple(temp2,temp3-0.1));
        }
        if(temp1==3){
            intervals.push_back(make_tuple(temp2+0.1,temp3));
        }
        if(temp1==4){
            if(temp2+0.1>temp3-0.1){
                continue;
            }
            else{
                intervals.push_back(make_tuple(temp2+0.1,temp3-0.1));
            }
        }
    }
    sort(intervals.begin(),intervals.end());
    long long ans = 0;
    for(int i=0;i<intervals.size();i++){
        int j = i+1;
        while(j<intervals.size() && get1(intervals[i])>=get0(intervals[j])){
            j++;ans++;
        };
    }
    printf("%lld\n",ans);
}