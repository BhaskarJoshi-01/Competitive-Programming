#include <bits/stdc++.h>
#define ll long long int
#define pr pair<ll, ll>
#define tp tuple<ll, ll, ll>
using namespace std;
long long int mod = 1e9 + 7;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k, ans = 0;
    cin >> k;
    for (ll i = 1; i <= k; i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            for (ll l = 1; l <= k; l++)
                ans += gcd(i, gcd(j, l));
        }
    }
    cout << ans << endl;
    return 0;
}