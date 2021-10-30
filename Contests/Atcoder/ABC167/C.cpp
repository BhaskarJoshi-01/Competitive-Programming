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

    ll n, m, x;
    cin >> n >> m >> x;
    ll c[n], a[n][m];
    for (ll i = 0; i < n; i++)
    {
        cin >> c[i];
        for (ll j = 0; j < m; j++)
            cin >> a[i][j];
    }
    ll ans = 1e16, val = pow(2, n);
    for (ll i = 0; i < val; i++)
    {
        ll temp = i, cost = 0, flag = 1, t[m];
        memset(t, 0, sizeof(t));
        for (ll j = 0; j < n; j++)
        {
            if (temp % 2 == 1)
            {
                cost += c[j];
                for (ll k = 0; k < m; k++)
                    t[k] += a[j][k];
            }
            temp /= 2;
        }
        for (ll j = 0; j < m; j++)
        {
            if (t[j] < x)
                flag = 0;
        }

        if (flag)
            ans = min(ans, cost);
    }
    if (ans == (ll)1e16)
        ans = -1;
    cout << ans << endl;
    return 0;
}