// Problem link: https://codeforces.com/problemset/problem/1506/E

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

void print_vector(vll v) {
    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}

struct Deque {
    int last_largest_number;
    deque<int> dq[2];
    Deque() {
        this->last_largest_number = 0;
    }
    void update_deque(int new_large) {
        for (int i = this->last_largest_number + 1; i < new_large; i++) {
            this->dq[0].push_back(i);
            this->dq[1].push_back(i);
        }
    }
    bool is_greater_than_last(int new_large) {
        if (new_large > this->last_largest_number) {
            this->update_deque(new_large);
            this->last_largest_number = new_large;
            return true;
        }
        return false;
    }
    void insert_numbers(vll &v_min, vll &v_max) {
        v_min.pb(this->dq[0].front());
        v_max.pb(this->dq[1].back());
        this->dq[0].pop_front();
        this->dq[1].pop_back();
    }
};

void solve() {
    int n;
    cin >> n;

    int a[n];
    vll ans[2];

    for (auto &x : a) {
        cin >> x;
    }

    Deque dq;

    for (int i = 0; i < n; i++) {
        if (dq.is_greater_than_last(a[i])) {
            ans[0].pb(a[i]);
            ans[1].pb(a[i]);
        } else {
            dq.insert_numbers(ans[0], ans[1]);
        }
    }

    print_vector(ans[0]);
    print_vector(ans[1]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}