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

void matrix_multiplication(ll a[100][100],ll b[100][100]){
    ll temp[100][100]={0};
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            for(int k=0;k<100;k++){
                temp[i][j] = (temp[i][j] + a[i][k]*b[k][j])%mod; 
            }
        }
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            a[i][j] = temp[i][j];
        }
    }
}

void modulo_expo(ll a[100][100], ll n, ll b){
    ll res[100][100]={0};
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(i == j){
                res[i][j] = 1;
            }
        }
    }
    while(b){
        if(b&1) matrix_multiplication(res,a);
        b >>=1;
        matrix_multiplication(a,a);
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            a[i][j] = res[i][j];
        }
    }
}

int main(){
    ll n,m,k;cin>>n>>m>>k;
    ll arr[100][100]={0};
    for(int i=0;i<m;i++){
        ll temp1,temp2;cin>>temp1>>temp2;
        arr[temp1-1][temp2-1]++;
    }
    modulo_expo(arr,n,k);
    write("\n",arr[0][n-1]);
}