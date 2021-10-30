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
        ll a[n];
        ll hash[n + 1];
        memset(hash, 0, sizeof(hash));
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            hash[a[i]]++;
        }
        ll count = 0;
        ll l1 = 0, l2 = 0, flag = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (l2 < l1)
            {
                flag = -1;
                break;
            }
            if (hash[i] == 2)
            {
                l1 = i;
                l2 = i;
            }
            else if (hash[i] == 1)
                l2 = i;
            else
                break;
        }
        if (l1 == 0 || l2 == 0 || l2 < l1 || flag == -1 || l1 + l2 != n)
        {
            cout << 0 << endl;
            continue;
        }
        vector<pr> v;
        ll hash2[n + 1], hash3[n + 1];
        memset(hash2, 0, sizeof(hash2));
        memset(hash3, 0, sizeof(hash3));
        for (ll i = 0; i < l1; i++)
        {
            hash2[a[i]]++;
        }
        for (ll i = l1; i < n; i++)
        {
            hash3[a[i]]++;
        }
        for (ll i = 1; i <= l1; i++)
        {
            if (hash2[i] != 1)
                flag = 1;
        }
        for (ll i = 1; i <= l2; i++)
        {
            if (hash3[i] != 1)
                flag = 1;
        }
        if (flag == 0)
        {
            count++;
            v.push_back({l1, l2});
        }
        flag = 0;
        memset(hash2, 0, sizeof(hash2));
        memset(hash3, 0, sizeof(hash3));
        for (ll i = 0; i < l2; i++)
        {
            hash2[a[i]]++;
        }
        for (ll i = l2; i < n; i++)
        {
            hash3[a[i]]++;
        }
        for (ll i = 1; i <= l2; i++)
        {
            if (hash2[i] != 1)
                flag = 1;
        }
        for (ll i = 1; i <= l1; i++)
        {
            if (hash3[i] != 1)
                flag = 1;
        }
        if (flag == 0)
        {
            count++;
            v.push_back({l2, l1});
        }
        if (l1 == l2 && count == 2)
            count = 1;
        cout << count << endl;
        for (ll i = 0; i < count; i++)
        {
            cout << v[i].first << " " << v[i].second << endl;
        }
    }
    return 0;
}