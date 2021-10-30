#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pr pair<ll, ll>
#define infinity (ll)4e18
#define maxpossible 9223372036854775807
#define tp tuple<ll, ll, ll>
using namespace std;
long long int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k;
    char s[6], t[6];
    cin >> k >> s >> t;
    ll s_count[9], t_count[9];
    memset(s_count, 0, sizeof(s_count));
    memset(t_count, 0, sizeof(t_count));
    for (ll i = 0; i < 4; i++)
        s_count[(int)(s[i] - '0')]++;
    for (ll i = 0; i < 4; i++)
        t_count[(int)(s[i] - '0')]++;

    double prob = 0;
    for (ll i = 1; i < 10; i++)
    {
        for (ll j = 1; j < 10; j++)
        {
            t_count[i]++;
            s_count[j]++;
            ll t_score = 0;
            for (ll i = 0; i < 9; i++)
                t_score += (i + 1) * pow(10, t_count[i]);
            ll s_score = 0;
            for (ll i = 0; i < 9; i++)
                s_score += (i + 1) * pow(10, s_count[i]);
            if (t_score > s_score)

                prob += probability;
            t_count[i]--;
            s_count[j]--;
        }
    }
    cout << prob << endl;

    return 0;
}