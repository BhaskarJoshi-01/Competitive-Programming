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

    ll a, b;
    cin >> a >> b;
    cout << (((float)a - b) / a) * 100;
    return 0;
}