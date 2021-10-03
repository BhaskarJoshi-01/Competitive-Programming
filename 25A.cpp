// Problem link: https://codeforces.com/problemset/problem/25/A

// Author: Akshat

#include <bits/stdc++.h>
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
#define ppll pair<ll, pll>
#define pld pair<ld, ld>
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(), X.end()
#define endl "\n"
#define sz(x) ((ll)((x).size()))
vll emptyVector;
const ll MAX = 2e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll binaryExpo(ll x, ll n) {
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return binaryExpo((x * x) % MOD, n / 2);
    return (x * binaryExpo((x * x) % MOD, n / 2)) % MOD;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

/*-------------------------------------------		CODE STARTS FROM HERE		------------------------------------------*/

void solve() {
    int n;
    cin >> n;
    int freq[2] = {0}, ans[2];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x % 2]++;
        ans[x% 2] = i + 1;
    }

    cout << (freq[0] > freq[1] ? ans[1] : ans[0]) << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--) {
    solve();
    // }

    return 0;
}