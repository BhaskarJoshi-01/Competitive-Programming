#include <bits/stdc++.h>
#define ll long long int
#define pr pair<ll, ll>
#define tp tuple<ll, ll, ll>
using namespace std;
long long int mod = 1e9 + 7;

ll nom(ll a, ll b)
{
    if (a >= b)
        return 0;
    ll diff = b - a;
    if ((diff & (diff - 1)) == 0)
        return log2(diff) + 1;
    ll moves = log2(diff);
    if (a + pow(2, moves) - 1 >= b)
        return moves;
    if (a + pow(2, moves + 1) - 1 >= b)
        return moves + 1;
}

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
        ll a[n], mini = INT_MAX, ans[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            ans[i] = a[i];
        }
        set<pr> s;
        for (ll i = 0; i < n; i++)
            s.insert({a[i], i});
        ll cur = 0, x = 0;
        while (!s.empty())
        {
            pr tem = *(s.begin());
            s.erase(s.find({a[cur], cur}));
            x = max(x, nom(tem.first, ans[cur]));
            cur++;
        }
        cout << x << endl;
    }
    return 0;
}