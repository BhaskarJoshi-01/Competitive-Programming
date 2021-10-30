#include <bits/stdc++.h>
#define ll long long int
#define pr pair<ll, ll>
#define tp tuple<ll, ll, ll>
using namespace std;
long long int mod = 1e9 + 7;

ll power(ll a, ll b)
{
    ll ans = 1;
    if (a == 0)
        return 0;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans % mod;
}
ll countgcd(ll n, ll dp[], ll k, ll pow[])
{
    if (dp[n] != -1)
        return dp[n];
    dp[n] = pow[n];
    for (ll i = 2; i * n <= k; i++)
    {
        dp[n] = (dp[n] - countgcd(i * n, dp, k, pow) + mod) % mod;
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    int pri[k + 1];
    memset(pri, 0, sizeof(pri));
    for (ll i = 2; i * i <= n; i++)
    {
        if (pri[i] == 0)
        {
            for (ll j = i * i; j <= n; j += i)
                pri[j] = 1;
        }
    }
    vector<ll> prime;
    for (ll i = 2; i < k + 1; i++)
    {
        if (pri[k] == 0)
            prime.push_back(i);
    }

    ll fac[k + 1], pow[k + 1];
    for (ll i = 1; i < k + 1; i++)
    {
        fac[i] = k / i;
        pow[i] = power(fac[i], n);
    }

    ll total = 0;
    ll dp[k + 1];
    memset(dp, -1, sizeof(dp));
    for (ll i = 1; i < k + 1; i++)
        total = (total + countgcd(i, dp, k, pow)) % mod;
    cout << (total + mod) % mod << endl;
    return 0;
}