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

    ll k, n;
    cin >> k >> n;
    ll a[n + 1];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
        cout << 0 << endl;
    else if (n == 2)
        cout << min(a[1] - a[0], k - (a[1] - a[0])) << endl;
    else
    {
        a[n] = k + a[0];
        ll mini = INT_MAX;
        for (ll i = 1; i <= n; i++)
        {
            if (k - (a[i] - a[i - 1]) < mini)
                mini = k - (a[i] - a[i - 1]);
        }
        cout << mini << endl;
    }

    return 0;
}