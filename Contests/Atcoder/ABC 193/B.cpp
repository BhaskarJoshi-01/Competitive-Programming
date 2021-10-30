#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pr pair<ll, ll>
#define infinity (ll)4e18
#define maxpossible 9223372036854775807
#define tp tuple<ll, ll, ll>
using namespace std;
long long int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ll a[n], p[n], x[n];
    ll min_price = infinity;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i] >> p[i] >> x[i];
        if (a[i] < x[i])
            min_price = min(min_price, p[i]);
    }
    if (min_price >= infinity)
        min_price = -1;
    cout << min_price;

    return 0;
}