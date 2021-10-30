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

    ll k, count = 1;
    cin >> k;
    ll ans[11] = {0};
    ans[0] = 1;
    for (ll i = 0; i < k - 1; i++)
    {
        ll flag = 0;
        for (ll j = count - 1; j > 0; j--)
        {
            if (ans[j] == 9)
                continue;
            if (ans[j - 1] - ans[j] == 1 || ans[j - 1] - ans[j] == 0)
            {
                ans[j]++;
                for (ll p = j + 1; p < count; p++)
                {
                    ans[p] = fmax(0, ans[p - 1] - 1);
                }
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            if (ans[0] != 9)
            {
                ans[0]++;
                for (ll j = 1; j < count; j++)
                {
                    ans[j] = fmax(0, ans[j - 1] - 1);
                }
            }
            else
            {
                count++;
                ans[0] = 1;
                for (ll j = 1; j < count; j++)
                {
                    ans[j] = 0;
                }
            }
        }
    }

    for (ll i = 0; i < count; i++)
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}