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

    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        int hash[1000];
        memset(hash, 0, sizeof(hash));
        for (ll i = 0; i < n; i++)
        {
            ll val;
            cin >> val;
            hash[val] = 1;
        }
        hash[0] = 1;
        ll i = 1;
        while (x > 0)
        {
            if (hash[i] == 0)
                x--;
            i++;
        }
        while (hash[i] == 1)
            i++;
        cout << i - 1 << endl;
    }
    return 0;
}