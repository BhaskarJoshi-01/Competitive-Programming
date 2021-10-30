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

    ll n;
    cin >> n;
    ll num = n - 1;
    ll ans = 0;
    for (ll i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            if (num / i == i)
                ans++;
            else
                ans += 2;
        }
    }
    ans--;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll val = i, temp = n;
            while (temp % val == 0)
                temp /= val;
            if (temp % val == 1)
                ans++;
            if (n / i != i)
            {
                ll val = n / i, temp = n;
                while (temp % val == 0)
                    temp /= val;
                if (temp % val == 1)
                    ans++;
            }
        }
    }
    ans++;
    cout << ans << endl;
    return 0;
}