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
        ll n, flag = 0;
        cin >> n;
        char s[n + 1];
        cin >> s;
        char a[n + 1], b[n + 1];
        a[n] = b[n] = '\0';
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
                a[i] = b[i] = '0';
            else if (s[i] == '2' && flag == 0)
                a[i] = b[i] = '1';
            else if (s[i] == '2' && flag == 1)
            {
                a[i] = '0';
                b[i] = '2';
            }
            else if (s[i] == '1' && flag == 0)
            {
                flag = 1;
                a[i] = '1';
                b[i] = '0';
            }
            else
            {
                a[i] = '0';
                b[i] = '1';
            }
        }
        cout << a << endl
             << b << endl;
    }
    return 0;
}