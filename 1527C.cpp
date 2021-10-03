// Problem link: https://codeforces.com/problemset/problem/1527/C

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

bool cmp(vll &v1, vll &v2) {
    if (v1[0] == v2[0]) {
        return v1[1] < v2[1];
    }
    return v1[0] < v2[0];
}

void print_vector(vvll v) {
    for (auto x : v) {
        cout << x[0] << " " << x[1] << endl;
    }
}

void solve() {
    int n;
    cin >> n;
    vvll v(n, vll(2));

    for (int i = 0; i < n; i++) {
        cin >> v[i][0];
        v[i][1] = i;
    }

    sort(v.begin(), v.end(), cmp);

    // print_vector(v);

    ll ans = 0, count = 0, sum_of_index = 0;

    for (int i = n - 2; i >= 0; i--) {
        if (v[i][0] == v[i + 1][0]) {
            sum_of_index += v[i + 1][1];
            count++;
            ans += (v[i][1] + 1) * (count * n - (sum_of_index));
        } else {
            sum_of_index = 0;
            count = 0;
        }
    }

    cout << ans << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}