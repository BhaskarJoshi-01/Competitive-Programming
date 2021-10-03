#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vvll vector<vll>
#define vld vector<ld>
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(), X.end()
#define rall(X) X.rbegin(), X.rend()
#define endl "\n"
#define sz(x) ((ll)((x).size()))
vll emptyVector;
const ll MAX = 2e5 + 1;
const ll INF = 1e10 + 1;
const ll MOD = 1e9 + 7;
const ld PI = acosl(-1);

ll binaryExpo(ll x, ll n) {
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return binaryExpo((x * x), n / 2) % MOD;
    return (x * binaryExpo((x * x), n / 2)) % MOD;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    // Using the fact that: a * b = lcm * gcm
    return a / gcd(a, b) * b;
}

// /*-------------------------------------------		CODE STARTS FROM HERE     ------------------------------------------*/

void solve() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // cin >> T;
    T = 1;
    for (int t = 1; t <= T; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}