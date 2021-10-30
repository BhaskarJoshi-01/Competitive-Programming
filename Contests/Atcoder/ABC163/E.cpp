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

    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll occu[n], moved[n];
    memset(moved, 0, sizeof(moved));
    memset(occu, 0, sizeof(occu));
    vector<tp> v;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            v.push_back(make_tuple(a[i] * abs(i - j), i, j));
        }
    }
    sort(v.begin(), v.end());
    ll count = 0, ans = 0, j = (ll)v.size() - 1;
    while (count < n)
    {
        ll a, b, c;
        tie(a, b, c) = v[j];
        j--;
        if (occu[c] == 1 || moved[b] == 1)
            continue;
        occu[c] = 1;
        moved[b] = 1;
        ans += a;
        count++;
    }
    cout << ans << endl;
    return 0;
}