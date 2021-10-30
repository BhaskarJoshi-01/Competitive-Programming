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

    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    ll ans = 0;
    if (k > a)
    {
        ans = a;
        k -= a;
        if (k > b)
        {
            k -= b;
            ans -= k;
        }
    }
    else
        ans = k;
    cout << ans << endl;
    return 0;
}