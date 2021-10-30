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
        ll n;
        cin >> n;
        ll a[n], b[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        reverse(b, b + n);
        ll ans[n];
        ll c = 0, i = 0, j = 0, flag = 0, k = 0;
        while (c < n)
        {
            if (flag == 0)
            {
                ans[k] = b[i];
                flag = 1;
                i++;
                c++;
                k++;
            }
            else
            {
                ans[k] = a[j];
                flag = 0;
                j++;
                c++;
                k++;
            }
        }
        reverse(ans, ans + n);
        for (ll i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}