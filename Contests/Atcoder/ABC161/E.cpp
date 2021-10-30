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

    ll n, k, c;
    cin >> n >> k >> c;
    char s[n + 1];
    cin >> s;
    ll pre[n], suf[n], sum = 0;
    if (s[0] == 'x')
        pre[0] = 1;
    else
        pre[0] = 0;
    for (ll i = 1; i <= c; i++)
    {
        if (s[i] == 'x')
            pre[i] = pre[i - 1];
        if (s[i] == 'o')
            pre[i] = 1;
    }
    for (ll i = c + 1; i < n; i++)
    {
        if (s[i] == 'x')
            pre[i] = pre[i - 1];
        else
            pre[i] = 1 + pre[i - c - 1];
    }
    if (s[n - 1] == 'x')
        suf[n - 1] = 1;
    else
        suf[n - 1] = 0;
    for (ll i = n - 2; i >= n - 1 - c; i--)
    {
        if (s[i] == 'x')
            suf[i] = suf[i + 1];
        if (s[i] == 'o')
            suf[i] = 1;
    }
    for (ll i = n - c - 2; i >= 0; i--)
    {
        if (s[i] == 'x')
            suf[i] = suf[i + 1];
        else
            suf[i] = 1 + suf[i + c + 1];
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll val = 0;
        if (s[i] == 'o')
        {
            if (i == 0)
                val += suf[1];
            else if (i == n - 1)
                val += pre[n - 2];
            else
                val = pre[i - 1] + suf[i + 1];
        }

        return 0;
    }