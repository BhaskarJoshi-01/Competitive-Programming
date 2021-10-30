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

    ll n, a, b;
    cin >> n;
    ll c[n];
    vector<pr> v[n + 1];
    for (ll i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        v[a].emplace_back(b, c[b]);
        v[b].emplace_back(a, c[a]);
    }
    return 0;
}