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
    ll a[m], sum = 0;
    for (ll i = 0; i < m; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (n >= sum)
        cout << n - sum << endl;
    else
        cout << -1 << endl;
    return 0;
}