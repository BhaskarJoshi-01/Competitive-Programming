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
        ll n, i = 1, j = 0, l;
        cin >> n >> l;
        while (l)
        {
            if (l - i > 0)
            {
                l -= i;
                i++;
            }
            else
            {
                j += l;
                j--;
                l = 0;
                break;
            }
        }
        char arr[n + 1];
        arr[n] = '\0';
        for (ll k = 0; k < n; k++)
        {
            if (k == i || k == j)
                arr[k] = 'b';
            else
                arr[k] = 'a';
        }
        for (ll j = n - 1; j >= 0; j--)
        {
            cout << arr[j];
        }
        cout << endl;
    }

    return 0;
}