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

    ll n, m;
    cin >> n >> m;
    ll a[n], sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    ll flag = 0;
    double val = (double)sum / (4 * (double)m);
    for (ll i = 0; i < m; i++)
    {
        if ((double)a[i] < val)
            flag = 1;
    }
    if (flag == 1)
        cout << "No\n";
    else
        cout << "Yes\n";
    return 0;
}