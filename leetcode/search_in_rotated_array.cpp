#include<bits/stdc++.h>
// #include<unistd.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
double PI = acos(-1);
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define st(v) sort(ALL(v))
#define revrs(v) reverse(ALL(v))
#define sta(arr, sz) sort(ALLA(arr, sz))
#define revrsa(arr, sz) reverse(ALLA(arr, sz))
#define tc(t) while (t--)
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

bool search(vector<int>v,int tar){
    int n =v.size();
    int st = 0;
    int en = v.size()-1;
    while (st<=en){
        int mid = (st+en)/2;
        if(v[mid]==tar || tar==v[0] || tar == v[n-1])return true;
        else if(v[mid]>v[0]){
            if(tar>v[mid]) st = mid+1;
            else if(tar<v[mid] && v[mid] == v[0]){
                st = mid+1;
                en--;
            }else if(tar<v[mid] && tar > v[0]){
                en = mid-1;
            }else{
                st = mid+1;
            }
        }else{
            if(tar < v[mid]){
                en = mid-1;
            }else if(tar > v[mid] && v[mid] == v[n-1]){
                en = mid-1;
                st++;
            }else if(tar > v[mid] && tar < v[n-1]){
                st = mid+1;
            }else{
                en = mid-1;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    tc(t){
        int n,tar;cin>>n>>tar;
        vector<int>v(n,0);
        for(int i=0;i<n;i++)cin>>v[i];
        cout<<search(v,tar)<<"\n";
    }
}