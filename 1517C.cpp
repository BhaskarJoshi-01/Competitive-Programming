// Problem link: https://codeforces.com/problemset/problem/1517/C

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
const ll MAX = 1e5;
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

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

/*-------------------------------------------		CODE STARTS FROM HERE		------------------------------------------*/

vvll ans;

bool can_go_left(int i, int j) {
    if (j - 1 < 0) {
        return false;
    }
    if (ans[i][j - 1] != 0) {
        return false;
    }
    return true;
}

void dfs(int i, int j, int val, int place_val) {
    ans[i][j] = place_val;
    if (val <= 0) {
        return;
    }
    if (can_go_left(i, j)) {
        dfs(i, j - 1, val - 1, place_val);
        return;
    }
    dfs(i + 1, j, val - 1, place_val);
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ans.pb(emptyVector);
        for (int j = 0; j < n; j++) {
            ans[i].pb(0);
        }
        ll x;
        cin >> x;
        ans[i][i] = x;
    }

    for (int i = 0; i < n; i++) {
        dfs(i, i, ans[i][i] - 1, ans[i][i]);
    }

    for (auto v : ans) {
        for (auto x : v) {
            if (x == 0) {
                break;
            }
            cout << x << " ";
        }
        cout << endl;
    }
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