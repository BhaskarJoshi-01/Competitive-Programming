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

int main(){
    ll n,k;cin>>n>>k;
    ll temp = k/n;
    ll arr[n];
    vector<pair<int,int>> t;
    int ke =0;
    for(int i=0;i<n;i++){
        cin>>ke;
        t.pb(mp(ke,i));
    }
    st(t);
    for(int i=0;i<n;i++){
        arr[i]=temp;
    }
    temp = k%n;
    int i=0;
    while(temp){
        arr[t[i].second]++;
        i++;
        temp--;
    }
    for(int i=0;i<n;i++)write(" ",arr[i]);
    write("","\n");
}