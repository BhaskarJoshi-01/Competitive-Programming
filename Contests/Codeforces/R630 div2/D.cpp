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

    ll k;
    cin >> k;
    cout << "3 3\n";
    ll a = pow(2, 17);
    cout << 2 * a - 1 << " " << a - 1 << " " << a - 1 << endl;
    cout << a + (a - 1 - k) << " " << a << " " << 2 * a - 1 << endl;
    cout << a + (a - 1 - k) << " " << a + (a - 1 - k) << " " << a - 1 << endl;
    return 0;
}