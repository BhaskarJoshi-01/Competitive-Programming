#include <bits/stdc++.h>
#define ll long long int
#define pr pair<ll, ll>
#define infinity (ll)4e18
#define tp tuple<ll, ll, ll>
using namespace std;
long long int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k;
    char s[1000];
    cin >> k;
    cin >> s;
    ll n = strlen(s);
    if (n <= k)
        cout << s << endl;
    else
    {
        for (ll i = 0; i < k; i++)
        {
            cout << s[i];
        }
        cout << "...\n";
    }
    return 0;
}