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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll x = b;
        ll z = c, y;
        if (b == c)
            y = b;
        else if (b > 1)
            y = c - 1;
        else
            y = c;
        cout << x << " " << y << " " << z << endl;
    }
    return 0;
}