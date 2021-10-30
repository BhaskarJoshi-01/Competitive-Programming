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

    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    ll ap[a + 1], gp[b + 1], cp[c + 1], dp[c + 1], pap[a + 1], pgp[b + 1], pcp[c + 1];
    pap[0] = pgp[0] = pcp[0] = 0;

    for (ll i = 1; i <= a; i++)
        cin >> ap[i];
    sort(ap + 1, ap + a + 1);
    reverse(ap + 1, ap + a + 1);
    for (ll i = 1; i <= a; i++)
        pap[i] = pap[i - 1] + ap[i];

    for (ll i = 1; i <= b; i++)
        cin >> gp[i];
    sort(gp + 1, gp + b + 1);
    reverse(gp + 1, gp + b + 1);
    for (ll i = 1; i <= b; i++)
        pgp[i] = pgp[i - 1] + gp[i];

    for (ll i = 1; i <= c; i++)
        cin >> cp[i];
    sort(cp + 1, cp + c + 1);
    reverse(cp + 1, cp + c + 1);
    for (ll i = 1; i <= c; i++)
        pcp[i] = pcp[i - 1] + cp[i];

    ll i = x, j = y, k, ans1, ans2;
    dp[0] = pap[x] + pgp[y];
    for (k = 1; k <= c; k++)
    {
        if (i == 0 && j == 0)
            break;
        ans1 = ans2 = -1;
        if (i > 0)
            ans1 = pcp[k] + pap[i - 1] + pgp[j];
        if (j > 0)
            ans2 = pcp[k] + pap[i] + pgp[j - 1];
        if (ans1 > ans2)
            i--;
        else
            j--;
        dp[k] = max(ans1, ans2);
    }
    ll maxi = INT_MIN;
    for (ll i = 0; i < c + 1; i++)
    {
        maxi = max(maxi, dp[i]);
    }
    cout << maxi << endl;
    return 0;
}