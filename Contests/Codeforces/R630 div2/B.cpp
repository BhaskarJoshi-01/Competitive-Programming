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

    ll pf[1010];
    for (ll i = 0; i < 1010; i++)
        pf[i] = i;

    for (ll i = 4; i < 1010; i += 2)
        pf[i] = 2;

    for (ll i = 3; i * i < 1010; i++)
    {
        if (pf[i] == i)
        {
            for (ll j = i * i; j < 1010; j += i)
            {
                if (pf[j] == j)
                    pf[j] = i;
            }
        }
    }

    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        set<ll> s;
        for (ll i = 0; i < n; i++)
        {
            if (s.count(pf[a[i]]) == 0)
                s.insert(pf[a[i]]);
        }
        vector<ll> v;
        while (!s.empty())
        {
            v.push_back(*s.begin());
            s.erase(s.begin());
        }
        cout << (ll)v.size() << endl;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < (ll)v.size(); j++)
            {
                if (v[j] == pf[a[i]])
                {
                    cout << j + 1 << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}