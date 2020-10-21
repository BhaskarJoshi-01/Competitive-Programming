#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vll vector < ll >
#define vvll vector < vll >
#define pll pair < ll,ll > 
#define ppll pair < ll, pll>
#define pld pair < ld,ld > 
#define vpll vector < pll >
#define all(X) X.begin(),X.end()
#define endl "\n"
#define sz(x) ((ll)((x).size()))
#define rall(X) X.rbegin(),X.rend()
vll emptyVector;
const ll MAX = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const ld pi = 3.141592653589793238462643383279502884197169399375105;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " is " << a << endl;
    err(++it, args...);
}

ll binaryExpo(ll x, ll n)
{
	if(n == 0)
		return 1;
	if(n % 2 == 0)
		return binaryExpo((x*x) % MOD, n/2);
	return (x*binaryExpo((x*x) % MOD, n/2)) % MOD;
}

ll gcd(ll a, ll b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}
/*-------------------------------------------		CODE STARTS FROM HERE		------------------------------------------*/


void solve(void)
{
	


}


int main(void)
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	// int t;
	// cin >> t;
	// while(t--)
	{
		solve();
	}
	




	return 0;
}
