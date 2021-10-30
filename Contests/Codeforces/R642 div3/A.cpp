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
        ll n, m, ans;
        cin >> n >> m;
        if (n == 1)
            ans = 0;
        else if (n == 2)
            ans = m;
        else
            ans = 2 * m;
        cout << ans << endl;
    }
    return 0;
}