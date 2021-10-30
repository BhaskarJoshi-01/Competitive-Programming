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

    char s[20], t[20];
    cin >> s >> t;
    ll sn = strlen(s), tn = strlen(t);
    ll flag = 0;
    if (tn != sn + 1)
        flag = 1;
    for (ll i = 0; i < sn; i++)
    {
        if (s[i] != t[i])
            flag = 1;
    }
    if (flag)
        cout << "No\n";
    else
        cout << "Yes\n";
    return 0;
}