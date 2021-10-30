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

void matrix_multiplication2(vector<vector<ll>> &mat1, vector<vector<ll>> mat2){
    int n = mat1.size();int m = mat1[0].size();
    int n1 = mat2.size(); int m2 = mat2[0].size();
    for(int i=0;i<n;i++){
        int arr[m2]={0};
        for(int j=0;j<m2;j++){
            for(int k=0;k<m;k++){
                arr[j] = (arr[j]+mat1[i][k]*mat2[k][j])%mod;
            }
        }
        for(int j=0;j<m2;j++){
            mat1[i][j] = arr[j];
        }
    }
}

int main(){
    int n,m,n1,m1;cin>>n>>m;
    vector<vector<ll>> arr(n,vector<ll>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>> arr[i][j];
        }
    }
    cin>>n1>>m1;
    vector<vector<ll>> brr(n1,vector<ll>(m1,0));
    for(int i=0;i<n1;i++){
        for(int j=0;j<m1;j++){
            cin>>brr[i][j];
        }
    }
    if(n1!=m){
        write("\n","Not Possible");
        return 0;
    }
    matrix_multiplication2(arr,brr);
    // for arrays :
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m1;j++){
    //         crr[i][j]=0;
    //         for(int k=0;k<m;k++){
    //             crr[i][j] += arr[i][k]*brr[k][j];
    //         }
    //     }
    // }
    for(int i=0;i<n;i++){
        for(int j=0;j<m1;j++){
            write(" ",arr[i][j]);
        }
        cout<<"\n";
    }
}