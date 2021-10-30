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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, flag = 1;
        cin >> n;
        ll a[n], ans[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll g = a[0];
        for (ll i = 0; i < n; i++)
        {
            if (a[i] != g)
            {
                g = -1;
                break;
            }
        }
        if (g != -1)
        {
            cout << 1 << endl;
            for (ll i = 0; i < n; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
            continue;
        }
        ans[0] = 1;
        for (ll i = 1; i < n; i++)
        {
            if (ans[i - 1] == 1)
                ans[i] = 2;
            else
                ans[i] = 1;
        }
        if (ans[0] == ans[n - 1] && a[0] != a[n - 1])
        {
            ll index = -1;
            for (ll i = 1; i < n; i++)
            {
                if (a[i] == a[i - 1])
                {
                    index = i;
                    break;
                }
            }
            if (index == -1)
                ans[n - 1] = 3;
            else
            {
                ans[index] = ans[index - 1];
                for (ll i = index + 1; i < n; i++)
                {
                    if (ans[i - 1] == 1)
                        ans[i] = 2;
                    else
                        ans[i] = 1;
                }
            }
        }
        for (ll i = 0; i < n; i++)
            flag = max(flag, ans[i]);
        cout << flag << endl;
        for (ll i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}