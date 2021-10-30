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
    ll l[m + 1], sum = 0, ans[n + 1];
    for (ll i = 1; i <= m; i++)
    {
        cin >> l[i];
        sum += l[i];
    }
    if (sum < n || m - 1 + l[m] > n)
    {
        cout << -1 << endl;
        return 0;
    }

    for (ll i = n - l[m] + 1; i <= n; i++)
        ans[i] = m;
    ll end = n - l[m];
    ll j = end, flag = 0, i = 1;
    for (i = m - 1; i > 0 && j > 0; i--)
    {
        ans[j] = i;
        j--;
        while (j + l[i] > n)
        {
            ans[j] = i;
            j--;
        }
        while (j >= i && l[i] > 1 && j > 0)
        {
            ans[j] = i;
            j--;
            l[i]--;
        }
    }
    ll ch = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (ans[i] == ch)
            ch++;
    }
    if (ch != m + 1)
        cout << -1 << endl;
    else
    {
        ll col = 1;
        for (ll i = 1; i <= n; i++)
        {
            if (ans[i] == col)
            {
                cout << i << " ";
                col++;
            }
        }
        cout << endl;
    }
    return 0;
}