#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pr pair<ll, ll>
#define infinity (ll)4e18
#define pi 3.14159265358979323846264
#define tp tuple<ll, ll, ll>
using namespace std;
long long int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b, h, m;
    cin >> a >> b >> h >> m;
    ld angle = abs(6 * m - 0.5 * (h * 60 + m));
    ld x = (pi * angle) / 180.0;
    ld ans = a * a + b * b - 2 * a * b * cos(x);
    ans = sqrt(ans);
    printf("%0.20Lf\n", ans);
    return 0;
}