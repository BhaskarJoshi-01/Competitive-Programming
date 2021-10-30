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
        ll n, k;
        cin >> n >> k;
        char s[n + 1];
        cin >> s;
        ll hash[k][26];
        memset(hash, 0, sizeof(hash));
        for (ll i = 0; i < n; i++)
            hash[i % k][(int)s[i] - 97]++;
        char ideal[k + 1];
        for (ll i = 0; i < k; i++)
        {
            ll index = 0;
            for (ll j = 0; j < 26; j++)
            {
                if (hash[i][j] + hash[k - 1 - i][j] > hash[i][index] + hash[k - 1 - i][index])
                    index = j;
            }
            ideal[i] = (char)(index + 97);
        }
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] != ideal[i % k])
                count++;
        }
        cout << count << endl;
    }
    return 0;
}