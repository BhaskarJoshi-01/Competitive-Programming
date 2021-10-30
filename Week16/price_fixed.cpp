#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<ll,ll>> inputs;

int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        ll temp1,temp2;cin>>temp1>>temp2;
        inputs.push_back(make_pair(temp2,temp1));
    }
    sort(inputs.begin(),inputs.end());
    int pointer1 = 0,pointer2 = n-1;
    ll price = 0;
    ll temp = 0;
    while(pointer1<=pointer2){
        while(temp<inputs[pointer1].first && pointer1<=pointer2 ){
            if(inputs[pointer2].second<(inputs[pointer1].first - temp)){
                temp += inputs[pointer2].second;
                price += (inputs[pointer2].second)*2;
                inputs[pointer2].second = 0;
                pointer2--;
            }
            else{
                ll l = ((ll)inputs[pointer1].first - temp); 
                temp += l;
                price += l*2;
                inputs[pointer2].second -=l;
            }
        }
        price += inputs[pointer1].second;
        temp += inputs[pointer1].second;
        inputs[pointer1].second = 0;
        pointer1++;
    }
    cout<<price<<"\n";
}