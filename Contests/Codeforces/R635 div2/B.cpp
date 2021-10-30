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
        ll x, n, m;
        cin >> x >> n >> m;
        ll nc = 0, mc = 0;
        while (nc < n && x > 20)
        {
            x /= 2;
            x += 10;
            nc++;
        }
        if (x - 10 * m > 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}