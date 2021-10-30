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

void mat_multi(ll mat1[2][2], ll mat2[2][2])
{
    ll x = ((mat1[0][0] * mat2[0][0])%mod + (mat1[0][1] * mat2[1][0])%mod)%mod;
    ll y = ((mat1[0][0] * mat2[0][1])%mod + (mat1[0][1] * mat2[1][1])%mod)%mod;
    ll z = ((mat1[1][0] * mat2[0][0])%mod + (mat1[1][1] * mat2[1][0])%mod)%mod;
    ll w = ((mat1[1][0] * mat2[0][1])%mod + (mat1[1][1] * mat2[1][1])%mod)%mod;
     
    mat1[0][0] = x;
    mat1[0][1] = y;
    mat1[1][0] = z;
    mat1[1][1] = w;
}


void power(ll mat1[2][2], ll n)
{
	if(n == 0 || n == 1) return;
	ll mat2[2][2] = {{1, 1}, {1, 0}};
	power(mat1, n / 2);
	mat_multi(mat1, mat1);
	if (n&1) mat_multi(mat1, mat2);
}

ll fabonacci(ll n)
{
	ll mat1[2][2] = {{1, 1}, {1, 0}};
	if (n == 0) return 0;
	power(mat1, n - 1);
	return mat1[0][0];
}

int main()
{
	ll n;cin>>n;
    write("\n",fabonacci(n));
}