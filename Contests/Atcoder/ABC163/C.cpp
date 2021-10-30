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

    ll n, x;
    cin >> n;
    ll a[n], hash[n + 1];
    memset(hash, 0, sizeof(hash));
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> x;
        hash[x]++;
    }
    for (ll i = 1; i < n + 1; i++)
    {
        cout << hash[i] << endl;
    }

    return 0;
}