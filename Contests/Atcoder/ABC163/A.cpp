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

    long double r;
    cin >> r;
    // printf("%0.20Lf\n", (long double)(2 * 3.141592653589793238 * r));
    long double ans = 2.0 * 3.141592653589793238 * r;
    cout << ans << endl;
    return 0;
}