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

    ll x;
    cin >> x;
    ll ans = 0;
    ans += (x / 500) * 1000;
    x %= 500;
    x = x - x % 5;
    ans += x;
    cout << ans << endl;
    return 0;
}