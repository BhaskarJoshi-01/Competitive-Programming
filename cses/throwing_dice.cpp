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

vector<vector<ll>> base_mat = {{32},{16},{8},{4},{2},{1}};

vector<vector<ll>> matrix_multiplication1(vector<vector<ll>> mat1, vector<vector<ll>> mat2){
    int n = mat1.size();int m = mat1[0].size();
    int n1 = mat2.size(); int m2 = mat2[0].size();
    vector<vector<ll>>ans;
    for(int i=0;i<n;i++){
        vector<ll>temp1;
        for(int j=0;j<m2;j++){
            ll temp = 0;
            for(int k=0;k<m;k++){
                temp  = (temp+mat1[i][k]*mat2[k][j])%mod;
            }
            temp1.pb(temp);
        }
        ans.pb(temp1);
    }
    return ans;
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

ll modulo_expo(vector<vector<ll>>&base_matrix,ll b){
    vector<vector<ll>> res = {{1,0,0,0,0,0},
                                {0,1,0,0,0,0},
                                {0,0,1,0,0,0},
                                {0,0,0,1,0,0},
                                {0,0,0,0,1,0},
                                {0,0,0,0,0,1}};
    while(b){
        if(b&1) matrix_multiplication2(res,base_matrix);
        b >>=1;
        matrix_multiplication2(base_matrix,base_matrix);
    }
    matrix_multiplication2(res,base_mat);
    return res[0][0];
}

ll number_of_ways(ll n){
    if(n<=6){
        return base_mat[6-n][0];
    }
    vector<vector<ll>> base = {{1,1,1,1,1,1},
                                {1,0,0,0,0,0},
                                {0,1,0,0,0,0},
                                {0,0,1,0,0,0},
                                {0,0,0,1,0,0},
                                {0,0,0,0,1,0}};
    
    ll ans = modulo_expo(base,(ll)n-6);
    return ans;
}

int main(){
    ll n;cin>>n;
    ll temp = number_of_ways(n);
    write("\n",temp);
}