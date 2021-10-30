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
        ll ans = 0, count = 0;
        for (ll i = 1; i <= n / 2; i++)
        {
            count += 8;
            ans += i * count;
        }
        cout << ans << endl;
    }
    return 0;
}