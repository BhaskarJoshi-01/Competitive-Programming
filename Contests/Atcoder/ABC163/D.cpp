#include <bits/stdc++.h>
#define ll long long int
#define pr pair<ll, ll>
#define tp tuple<ll, ll, ll>
using namespace std;
long long int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    ll a[n + 1];
    for (ll i = 0; i < n + 1; i++)
    {
        a[i] = i;
    }
    ll sum[n + 1], bac[n + 1];
    sum[0] = 0;
    for (ll i = 1; i < n + 1; i++)
        sum[i] = a[i] + sum[i - 1];
    bac[n] = a[n];
    for (ll i = n - 1; i >= 0; i--)
        bac[i] = bac[i + 1] + a[i];
    ll ans = 0;
    for (ll i = k; i <= n + 1; i++)
    {
        ans += (bac[n + 1 - i] - sum[i - 1] + 1 + mod) % mod;
    }

    cout << ans % mod << endl;

    return 0;
}