#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
double PI = acos(-1);
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define st(v) sort(ALL(v))
#define revrs(v) reverse(ALL(v))
#define sta(arr, sz) sort(ALLA(arr, sz))
#define revrsa(arr, sz) reverse(ALLA(arr, sz))
#define TC(t) while (t--)
//  For debug
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout<<"\n";
}
template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}
template <typename... T>
void write(string delimiter, T &&...args) {
    ((cout << args << delimiter), ...);
}
template <typename T>
void readContainer(T &t) {
    for (auto &e : t) {
        read(e);
    }
}
template <typename T>
void writeContainer(string delimiter, T &t) {
    for (const auto &e : t) {
        write(delimiter, e);
    }
    write("\n");
}

void dfs(vector<vector<int>>&arr,int n,int i,vector<bool>&visited){
    visited[i]=true;
    for(int j=0;j<arr[i].size();j++){
        if(!visited[arr[i][j]]) dfs(arr,n,arr[i][j],visited);
    }
    return;
}

int ret_val(vector<vector<int>> &arr,int n){
    vector<bool>visited(n,false);
    int ans=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            ans++;
            dfs(arr,n,i,visited);
        }
    }
    return ans;
}

int  modulo_expo(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = ((ll)res*a)%mod;
        a = ((ll)a*a)%mod;
        b>>=1;
    }
    return res;
}

int main(){
    int t;cin>>t;
    TC(t){
        int n;cin>>n;
        vector<vector<int>> edges(n,vector<int>());
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++){
            int temp;cin>>temp;
            edges[arr[i]-1].push_back(temp-1);
        }
        int _power = ret_val(edges,n);
        int ans = modulo_expo(2,_power);
        write("\n",ans);
    }
}