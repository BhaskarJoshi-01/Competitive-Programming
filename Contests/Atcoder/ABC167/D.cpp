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

    ll n, k;
    cin >> n >> k;
    ll a[n + 1];
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    set<ll> s;
    vector<ll> v;
    ll cur = 1;
    s.insert(1);
    v.push_back(1);
    while (3)
    {
        cur = a[cur];
        if (s.count(cur) == 1)
            break;
        s.insert(cur);
        v.push_back(cur);
    }
    ll ans = 1, i = 0;
    while (k && v[i] != cur)
    {
        i++;
        k--;
    }
    ll size = v.size() - i;
    k = k % size;
    while (k)
    {
        i++;
        k--;
    }
    cout << v[i] << endl;
    return 0;
}